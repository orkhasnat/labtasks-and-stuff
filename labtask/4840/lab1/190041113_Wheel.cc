// 190041113 - Wheel

#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/internet-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include <cstdint>
using namespace ns3;

NS_LOG_COMPONENT_DEFINE("Star-Ring/Wheel Topology");

int main(int argc, char* argv[])
{
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    uint32_t max_packets = 2;
    uint32_t N = 8;
    uint16_t port = 2852;

    NodeContainer nodes;
    nodes.Create(N);

    MobilityHelper mobility;
    double radius = 5.0;
    Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator>();
    positionAlloc->Add(Vector(0.0, 0.0, 0.0));
    mobility.SetPositionAllocator(positionAlloc);
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(nodes.Get(0));

    for (uint32_t i = 1; i < N; i++)
    {
        double theta = (i - 1) * 2.0 * M_PI / (N - 1);
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        Ptr<ListPositionAllocator> positionAllocRing = CreateObject<ListPositionAllocator>();
        positionAllocRing->Add(Vector(x, y, 0.0));
        mobility.SetPositionAllocator(positionAllocRing);
        mobility.Install(nodes.Get(i));
    }

    InternetStackHelper internet;
    internet.Install(nodes);

    std::vector<NodeContainer> nodeAdjacencyList;
    for (uint32_t i = 1; i < N; ++i)
    {
        nodeAdjacencyList.push_back(NodeContainer(nodes.Get(0), nodes.Get(i)));
        nodeAdjacencyList.push_back(
            NodeContainer(nodes.Get((i == N - 1 ? 1 : i + 1)), nodes.Get(i)));
    }

    PointToPointHelper p2p;
    p2p.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    p2p.SetChannelAttribute("Delay", StringValue("2ms"));

    std::vector<NetDeviceContainer> deviceAdjacencyList;
    for (uint32_t i = 0; i < nodeAdjacencyList.size(); ++i)
    {
        deviceAdjacencyList.push_back(p2p.Install(nodeAdjacencyList[i]));
    }

    Ipv4AddressHelper ipv4;
    std::vector<Ipv4InterfaceContainer> interfaceAdjacencyList;
    for (uint32_t i = 0; i < deviceAdjacencyList.size(); ++i)
    {
        std::stringstream subnet;
        subnet << "10.3.13." << i * (256 / deviceAdjacencyList.size());
        std::stringstream mask;
        mask << "255.255.255."
             << (0xff & (0xff << (uint8_t)std::ceil(log2(deviceAdjacencyList.size()))));
        ipv4.SetBase(subnet.str().c_str(), mask.str().c_str());
        interfaceAdjacencyList.push_back(ipv4.Assign(deviceAdjacencyList[i]));
    }

    Ipv4GlobalRoutingHelper::PopulateRoutingTables();

    ApplicationContainer clientApps;
    for (uint32_t i = 0; i < nodeAdjacencyList.size(); ++i)
    {
        UdpEchoServerHelper echoServerHelper(port + i);
        ApplicationContainer serverApps = echoServerHelper.Install(nodeAdjacencyList[i].Get(0));
        serverApps.Start(Seconds(i * 4 + 1.0));
        serverApps.Stop(Seconds(i * 4));

        Ipv4Address serverAddress = interfaceAdjacencyList[i].GetAddress(0);
        UdpEchoClientHelper echoClientHelper(serverAddress, port + i);
        echoClientHelper.SetAttribute("MaxPackets", UintegerValue(max_packets));
        echoClientHelper.SetAttribute("Interval", TimeValue(Seconds(0.5)));
        echoClientHelper.SetAttribute("PacketSize", UintegerValue(1024));

        ApplicationContainer clientApps = echoClientHelper.Install(nodeAdjacencyList[i].Get(1));
        clientApps.Start(Seconds(2.0 + i * 4));
        clientApps.Stop(Seconds(4 * i));
    }

    AnimationInterface anim("190041113_Wheel.xml");
    anim.SetConstantPosition(nodes.Get(0), 0.0, 0.0);
    for (uint32_t i = 1; i < N; i++)
    {
        double theta = (i - 1) * 2.0 * M_PI / (N - 1);
        anim.SetConstantPosition(nodes.Get(i), radius * cos(theta), radius * sin(theta));
    }

    NS_LOG_INFO("Run Simulation.");
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");

    return 0;
}
