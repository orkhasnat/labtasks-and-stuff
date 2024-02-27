#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-apps-module.h"
#include "ns3/internet-module.h"
#include "ns3/ipv4-routing-table-entry.h"
#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h"

#include <fstream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("RipSimpleRouting");

void
TearDownLink(Ptr<Node> nodeA, Ptr<Node> nodeB, uint32_t interfaceA, uint32_t interfaceB)
{
    nodeA->GetObject<Ipv4>()->SetDown(interfaceA);
    nodeB->GetObject<Ipv4>()->SetDown(interfaceB);
}

void
SetMobility(Ptr<Node> node, double x, double y)
{
    MobilityHelper mobility;
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    Ptr<ListPositionAllocator> positionAllocRing = CreateObject<ListPositionAllocator>();
    positionAllocRing->Add(Vector(x, y, 0.0));
    mobility.SetPositionAllocator(positionAllocRing);
    mobility.Install(node);
}

int
main(int argc, char** argv)
{
    bool verbose = false;
    bool printRoutingTables = true;
    bool showPings = false;
    std::string SplitHorizon("PoisonReverse");

    CommandLine cmd(__FILE__);
    cmd.AddValue("verbose", "turn on log components", verbose);
    cmd.AddValue("printRoutingTables",
                 "Print routing tables at 30, 60 and 90 seconds",
                 printRoutingTables);
    cmd.AddValue("showPings", "Show Ping6 reception", showPings);
    cmd.AddValue("splitHorizonStrategy",
                 "Split Horizon strategy to use (NoSplitHorizon, SplitHorizon, PoisonReverse)",
                 SplitHorizon);
    cmd.Parse(argc, argv);

    if (verbose)
    {
        LogComponentEnableAll(LogLevel(LOG_PREFIX_TIME | LOG_PREFIX_NODE));
        LogComponentEnable("RipSimpleRouting", LOG_LEVEL_INFO);
        LogComponentEnable("Rip", LOG_LEVEL_ALL);
        LogComponentEnable("Ipv4Interface", LOG_LEVEL_ALL);
        LogComponentEnable("Icmpv4L4Protocol", LOG_LEVEL_ALL);
        LogComponentEnable("Ipv4L3Protocol", LOG_LEVEL_ALL);
        LogComponentEnable("ArpCache", LOG_LEVEL_ALL);
        LogComponentEnable("V4Ping", LOG_LEVEL_ALL);
    }

    if (SplitHorizon == "NoSplitHorizon")
    {
        Config::SetDefault("ns3::Rip::SplitHorizon", EnumValue(RipNg::NO_SPLIT_HORIZON));
    }
    else if (SplitHorizon == "SplitHorizon")
    {
        Config::SetDefault("ns3::Rip::SplitHorizon", EnumValue(RipNg::SPLIT_HORIZON));
    }
    else
    {
        Config::SetDefault("ns3::Rip::SplitHorizon", EnumValue(RipNg::POISON_REVERSE));
    }

    NS_LOG_INFO("Create nodes.");
    // Hosts
    Ptr<Node> n0 = CreateObject<Node>();
    Names::Add("Host1", n0);
    Ptr<Node> n1 = CreateObject<Node>();
    Names::Add("Host2", n1);
    Ptr<Node> n2 = CreateObject<Node>();
    Names::Add("Host3", n2);
    Ptr<Node> n8 = CreateObject<Node>();
    Names::Add("Host4", n8);

    // Routers
    Ptr<Node> n3 = CreateObject<Node>();
    Names::Add("Router1", n3);
    Ptr<Node> n4 = CreateObject<Node>();
    Names::Add("Router2", n4);
    Ptr<Node> n5 = CreateObject<Node>();
    Names::Add("Router3", n5);
    Ptr<Node> n6 = CreateObject<Node>();
    Names::Add("Router4", n6);
    Ptr<Node> n7 = CreateObject<Node>();
    Names::Add("Router5", n7);

    NodeContainer net1(n0, n3);
    NodeContainer net2(n1, n3);
    NodeContainer net3(n2, n3);
    NodeContainer net4(n3, n4);
    
    NodeContainer net5(n4, n5);
    NodeContainer net6(n4, n6);
    NodeContainer net7(n4, n7);
    NodeContainer net8(n5, n6);
    NodeContainer net9(n5, n7);
    NodeContainer net10(n6, n7);
    
    NodeContainer net11(n7, n8);
    NodeContainer routers(n3, n4, n5, n6, n7);
    NodeContainer nodes(n0, n1, n2, n8);


    SetMobility(nodes.Get(0), 30.0,0.0);
    SetMobility(nodes.Get(1), 40.0, 10.0);
    SetMobility(nodes.Get(2), 50.0, 20);
    SetMobility(nodes.Get(3), 0.0, 50.0);

    SetMobility(routers.Get(0), 30.0,20.0);
    SetMobility(routers.Get(1), 20,30);
    SetMobility(routers.Get(2), 20,40);
    SetMobility(routers.Get(3), 10.0, 30.0);
    SetMobility(routers.Get(4), 10.0,40.0);
    NS_LOG_INFO("Create channels.");
    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", DataRateValue(5000000));
    csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));
    NetDeviceContainer ndc1 = csma.Install(net1);
    NetDeviceContainer ndc2 = csma.Install(net2);
    NetDeviceContainer ndc3 = csma.Install(net3);
    NetDeviceContainer ndc4 = csma.Install(net4);
    NetDeviceContainer ndc5 = csma.Install(net5);
    NetDeviceContainer ndc6 = csma.Install(net6);
    NetDeviceContainer ndc7 = csma.Install(net7);
    NetDeviceContainer ndc8 = csma.Install(net8);
    NetDeviceContainer ndc9 = csma.Install(net9);
    NetDeviceContainer ndc10 = csma.Install(net10);
    NetDeviceContainer ndc11 = csma.Install(net11);

    NS_LOG_INFO("Create IPv4 and routing");
    RipHelper ripRouting;

    // Rule of thumb:
    // Interfaces are added sequentially, starting from 0
    // However, interface 0 is always the loopback...
    //
    ripRouting.ExcludeInterface(n3, 1);
    ripRouting.ExcludeInterface(n3, 2);
    ripRouting.ExcludeInterface(n3, 3);
    ripRouting.ExcludeInterface(n7, 4);

    ripRouting.SetInterfaceMetric(n5, 3, 5);
    ripRouting.SetInterfaceMetric(n7, 2, 5);

    ripRouting.SetInterfaceMetric(n6, 3, 10);
    ripRouting.SetInterfaceMetric(n7, 3, 10);

    Ipv4ListRoutingHelper listRH;
    listRH.Add(ripRouting, 0);
   
    InternetStackHelper internet;
    internet.SetIpv6StackInstall(false);
    internet.SetRoutingHelper(listRH);
    internet.Install(routers);

    InternetStackHelper internetNodes;
    internetNodes.SetIpv6StackInstall(false);
    internetNodes.Install(nodes);

  
    NS_LOG_INFO("Assign IPv4 Addresses.");
    Ipv4AddressHelper ipv4;

    ipv4.SetBase(Ipv4Address("10.0.0.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic1 = ipv4.Assign(ndc1);

    ipv4.SetBase(Ipv4Address("10.0.1.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic2 = ipv4.Assign(ndc2);

    ipv4.SetBase(Ipv4Address("10.0.2.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic3 = ipv4.Assign(ndc3);

    ipv4.SetBase(Ipv4Address("10.0.3.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic4 = ipv4.Assign(ndc4);

    ipv4.SetBase(Ipv4Address("10.0.4.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic5 = ipv4.Assign(ndc5);

    ipv4.SetBase(Ipv4Address("10.0.5.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic6 = ipv4.Assign(ndc6);

    ipv4.SetBase(Ipv4Address("10.0.6.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic7 = ipv4.Assign(ndc7);
    
    ipv4.SetBase(Ipv4Address("10.0.7.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic8 = ipv4.Assign(ndc8);
    
    ipv4.SetBase(Ipv4Address("10.0.8.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic9 = ipv4.Assign(ndc9);
    
    ipv4.SetBase(Ipv4Address("10.0.9.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic10 = ipv4.Assign(ndc10);
    
    ipv4.SetBase(Ipv4Address("10.0.10.0"), Ipv4Mask("255.255.255.0"));
    Ipv4InterfaceContainer iic11 = ipv4.Assign(ndc11);


    Ptr<Ipv4StaticRouting> staticRouting;
    staticRouting = Ipv4RoutingHelper::GetRouting<Ipv4StaticRouting>(
        n0->GetObject<Ipv4>()->GetRoutingProtocol());
    staticRouting->SetDefaultRoute("10.0.0.2", 1);
    staticRouting = Ipv4RoutingHelper::GetRouting<Ipv4StaticRouting>(
        n1->GetObject<Ipv4>()->GetRoutingProtocol());
    staticRouting->SetDefaultRoute("10.0.1.2", 1);
    staticRouting = Ipv4RoutingHelper::GetRouting<Ipv4StaticRouting>(
        n2->GetObject<Ipv4>()->GetRoutingProtocol());
    staticRouting->SetDefaultRoute("10.0.2.2", 1);
    staticRouting = Ipv4RoutingHelper::GetRouting<Ipv4StaticRouting>(
        n8->GetObject<Ipv4>()->GetRoutingProtocol());
    staticRouting->SetDefaultRoute("10.0.10.1", 1);

  
    if (printRoutingTables)
    {
        RipHelper routingHelper;

        Ptr<OutputStreamWrapper> routingStream = Create<OutputStreamWrapper>(&std::cout);
        std::vector<uint32_t> intervals = {20, 40, 60, 80};
        for (uint32_t i : intervals)
        {
            for (uint32_t j = 0; j < routers.GetN(); j++)
            {
                routingHelper.PrintRoutingTableAt(Seconds(i), routers.Get(j), routingStream);
            }
        }
    }

    NS_LOG_INFO("Create Applications.");
    uint32_t packetSize = 1024;
    Time interPacketInterval = Seconds(1.0);
    V4PingHelper ping("10.0.10.2");

    ping.SetAttribute("Interval", TimeValue(interPacketInterval));
    ping.SetAttribute("Size", UintegerValue(packetSize));
    if (showPings)
    {
        ping.SetAttribute("Verbose", BooleanValue(true));
    }
    ApplicationContainer apps;
    apps.Add(ping.Install(n0));
    apps.Add(ping.Install(n1));
    apps.Add(ping.Install(n2));
    apps.Start(Seconds(1.0));
    apps.Stop(Seconds(150.0));

    Simulator::Schedule(Seconds(30), &TearDownLink, n4, n7, 4, 1);
    Simulator::Schedule(Seconds(50), &TearDownLink, n5, n6, 2, 2);

    /* Now, do the actual simulation. */
    AnimationInterface anim("lab2p.xml");
    SetMobility(nodes.Get(0), 30.0,0.0);
    SetMobility(nodes.Get(1), 40.0, 10.0);
    SetMobility(nodes.Get(2), 50.0, 20);
    SetMobility(nodes.Get(3), 0.0, 50.0);

    SetMobility(routers.Get(0), 30.0,20.0);
    SetMobility(routers.Get(1), 20,30);
    SetMobility(routers.Get(2), 20,40);
    SetMobility(routers.Get(3), 10.0, 30.0);
    SetMobility(routers.Get(4), 10.0,40.0);
    NS_LOG_INFO("Run Simulation.");
    Simulator::Stop(Seconds(150.0));
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");

    return 0;
}

