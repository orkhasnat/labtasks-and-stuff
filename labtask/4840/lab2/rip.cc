// 190041113

#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-apps-module.h"
#include "ns3/internet-module.h"
#include "ns3/ipv4-routing-table-entry.h"
#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h"
#include <cstdint>
using namespace ns3;

NS_LOG_COMPONENT_DEFINE("RIP-SimpleRouting");

void TearDownLink(Ptr<Node> nodeA, Ptr<Node> nodeB, uint32_t interfaceA, uint32_t interfaceB)
{
    nodeA->GetObject<Ipv4>()->SetDown(interfaceA);
    nodeB->GetObject<Ipv4>()->SetDown(interfaceB);
}

void SetMobility(Ptr<Node> node, double x, double y)
{
    MobilityHelper mobility;
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    Ptr<ListPositionAllocator> positionAllocRing = CreateObject<ListPositionAllocator>();
    positionAllocRing->Add(Vector(x, y, 0.0));
    mobility.SetPositionAllocator(positionAllocRing);
    mobility.Install(node);
}

int main(int argc, char** argv)
{
    bool verbose = false;
    bool printRoutingTables = true;
    bool showPings = false;
    std::string SplitHorizon("PoisonReverse");

    CommandLine cmd(__FILE__);
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
    NodeContainer hosts;
    hosts.Create(4);
    NodeContainer routers;
    routers.Create(5);

    Names::Add("n0", hosts.Get(0));
    Names::Add("n1", hosts.Get(1));
    Names::Add("n2", hosts.Get(2));
    Names::Add("n8", hosts.Get(3));

    Names::Add("n3", routers.Get(0));
    Names::Add("n4", routers.Get(1));
    Names::Add("n5", routers.Get(2));
    Names::Add("n6", routers.Get(3));
    Names::Add("n7", routers.Get(4));

    auto d = 5;
    SetMobility(hosts.Get(0), d * 3.0, -d * 4.0);
    SetMobility(hosts.Get(1), d * 4.0, -d * 4.0);
    SetMobility(hosts.Get(2), d * 4.0, -d * 3.0);
    SetMobility(hosts.Get(3), d * 0.0, -d * 0.0);

    SetMobility(routers.Get(0), d * 3.0, -d * 3.0);
    SetMobility(routers.Get(1), d * 2.0, -d * 2.0);
    SetMobility(routers.Get(2), d * 2.0, -d * 1.0);
    SetMobility(routers.Get(3), d * 1.0, -d * 2.0);
    SetMobility(routers.Get(4), d * 1.0, -d * 1.0);

    NS_LOG_INFO("Create channels.");
    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", DataRateValue(5000000));
    csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));

    std::vector<NetDeviceContainer> devAdjList;
    devAdjList.push_back(csma.Install(NodeContainer(hosts.Get(0), routers.Get(0))));
    devAdjList.push_back(csma.Install(NodeContainer(hosts.Get(1), routers.Get(0))));
    devAdjList.push_back(csma.Install(NodeContainer(hosts.Get(2), routers.Get(0))));
    devAdjList.push_back(csma.Install(NodeContainer(hosts.Get(3), routers.Get(4))));

    devAdjList.push_back(csma.Install(NodeContainer(routers.Get(0), routers.Get(1))));
    devAdjList.push_back(csma.Install(NodeContainer(routers.Get(1), routers.Get(2))));
    devAdjList.push_back(csma.Install(NodeContainer(routers.Get(1), routers.Get(3))));
    // teardown at 30s
    devAdjList.push_back(csma.Install(NodeContainer(routers.Get(1), routers.Get(4))));
    // teardown at 50s
    devAdjList.push_back(csma.Install(NodeContainer(routers.Get(2), routers.Get(3))));
    // the following two links will have costs 5 and 10 in the rip
    devAdjList.push_back(csma.Install(NodeContainer(routers.Get(2), routers.Get(4))));
    devAdjList.push_back(csma.Install(NodeContainer(routers.Get(3), routers.Get(4))));

    NS_LOG_INFO("Create IPv4 and routing");
    RipHelper ripRouting;

    // Rule of thumb:
    // Interfaces are added sequentially, starting from 0
    // However, interface 0 is always the loopback...
    ripRouting.ExcludeInterface(routers.Get(0), 1);
    ripRouting.ExcludeInterface(routers.Get(0), 2);
    ripRouting.ExcludeInterface(routers.Get(0), 3);
    ripRouting.ExcludeInterface(routers.Get(4), 1);

    ripRouting.SetInterfaceMetric(routers.Get(2), 3, 5);
    ripRouting.SetInterfaceMetric(routers.Get(4), 3, 5);

    ripRouting.SetInterfaceMetric(routers.Get(3), 3, 10);
    ripRouting.SetInterfaceMetric(routers.Get(4), 4, 10);

    Ipv4ListRoutingHelper listRH;
    listRH.Add(ripRouting, 0);

    InternetStackHelper internet;
    internet.SetIpv6StackInstall(false);
    internet.SetRoutingHelper(listRH);
    internet.Install(routers);

    InternetStackHelper internetNodes;
    internetNodes.SetIpv6StackInstall(false);
    internetNodes.Install(hosts);

    // Assign addresses.
    // The source and destination networks have global addresses
    // The "core" network just needs link-local addresses for routing.
    // We assign global addresses to the routers as well to receive
    // ICMPv6 errors.
    NS_LOG_INFO("Assign IPv4 Addresses.");
    Ipv4AddressHelper ipv4;

    std::vector<Ipv4InterfaceContainer> IICs;
    for (uint32_t i = 0; i < devAdjList.size(); i++)
    {
        std::stringstream subnet;
        subnet << "10.0." << i << ".0";
        ipv4.SetBase(Ipv4Address(subnet.str().c_str()), Ipv4Mask("255.255.255.0"));
        IICs.push_back(ipv4.Assign(devAdjList[i]));
    }

    for (uint32_t i = 0; i < 4; i++)
    {
        Ptr<Ipv4StaticRouting> staticRouting;
        Ptr<Node> n = hosts.Get(i);
        staticRouting = Ipv4RoutingHelper::GetRouting<Ipv4StaticRouting>(
            n->GetObject<Ipv4>()->GetRoutingProtocol());
        staticRouting->SetDefaultRoute(IICs[i].GetAddress(1), 1);
    }

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
    Time interPacketInterval = Seconds(0.5);
    V4PingHelper ping(IICs[3].GetAddress(0));

    ping.SetAttribute("Interval", TimeValue(interPacketInterval));
    ping.SetAttribute("Size", UintegerValue(packetSize));
    if (showPings)
    {
        ping.SetAttribute("Verbose", BooleanValue(true));
    }
    ApplicationContainer apps;
    for (uint32_t i = 0; i < 3; i++)
    {
        apps.Add(ping.Install(hosts.Get(i)));
    }
    apps.Start(Seconds(1));
    apps.Stop(Seconds(100));

    /* AsciiTraceHelper ascii; */
    /* csma.EnableAsciiAll(ascii.CreateFileStream("rip-simple-routing.tr")); */
    /* csma.EnablePcapAll("rip-simple-routing", true); */

    Simulator::Schedule(Seconds(30), &TearDownLink, routers.Get(1), routers.Get(4), 4, 2);
    Simulator::Schedule(Seconds(50), &TearDownLink, routers.Get(2), routers.Get(3), 2, 2);

    AnimationInterface anim("190041113.xml");
    anim.SetConstantPosition(hosts.Get(0), d * 3.0, -d * 4.0);
    anim.SetConstantPosition(hosts.Get(1), d * 4.0, -d * 4.0);
    anim.SetConstantPosition(hosts.Get(2), d * 4.0, -d * 3.0);
    anim.SetConstantPosition(hosts.Get(3), d * 0.0, -d * 0.0);

    anim.SetConstantPosition(routers.Get(0), d * 3.0, -d * 3.0);
    anim.SetConstantPosition(routers.Get(1), d * 2.0, -d * 2.0);
    anim.SetConstantPosition(routers.Get(2), d * 2.0, -d * 1.0);
    anim.SetConstantPosition(routers.Get(3), d * 1.0, -d * 2.0);
    anim.SetConstantPosition(routers.Get(4), d * 1.0, -d * 1.0);

    /* Now, do the actual simulation. */
    NS_LOG_INFO("Run Simulation.");
    Simulator::Stop(Seconds(100.0));
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");

    return 0;
}
