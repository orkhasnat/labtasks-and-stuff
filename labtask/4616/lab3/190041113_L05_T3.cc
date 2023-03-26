/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ssid.h"
#include "ns3/yans-wifi-helper.h"
#include "ns3/netanim-module.h"
#include "ns3/flow-monitor-module.h"


// Default Network Topology
//
//   Wifi 10.1.1.0
//                           AP  
//  *    *    *    *    *    *
//  |    |    |    |    |    |        10.1.2.0
// n0   n1   n2   n3   n4    n5    --------------  n6   n7   n8   n9   n10  n11  
//                                 point-to-point  |    |    |    |    |    |    
//                                                 *    *    *    *    *    *    
//                                                AP        
//							                              WiFi 10.1.3.0

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("ThirdScriptExample");

int
main(int argc, char* argv[])
{
    bool verbose = true;
    uint32_t nWifi = 5;
    bool tracing = false;

    CommandLine cmd(__FILE__);
    // cmd.AddValue("nCsma", "Number of \"extra\" CSMA nodes/devices", nCsma);
    cmd.AddValue("nWifi", "Number of wifi STA devices", nWifi);
    cmd.AddValue("verbose", "Tell echo applications to log if true", verbose);
    cmd.AddValue("tracing", "Enable pcap tracing", tracing);

    cmd.Parse(argc, argv);

    // The underlying restriction of 18 is due to the grid position
    // allocator's configuration; the grid layout will exceed the
    // bounding box if more than 18 nodes are provided.
    if (nWifi > 18)
    {
        std::cout << "nWifi should be 18 or less; otherwise grid layout exceeds the bounding box"
                  << std::endl;
        return 1;
    }

    if (verbose)
    {
        LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
        LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
    }

    NodeContainer p2pNodes;
    p2pNodes.Create(2);

    PointToPointHelper pointToPoint;
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));

    NetDeviceContainer p2pDevices;
    p2pDevices = pointToPoint.Install(p2pNodes);

    NodeContainer wifiStaNodes1, wifiStaNodes2;
    wifiStaNodes1.Create(nWifi);
    wifiStaNodes2.Create(nWifi);

    NodeContainer wifiApNodes;
    wifiApNodes.Add(p2pNodes.Get(0));
    wifiApNodes.Add(p2pNodes.Get(1));

    YansWifiChannelHelper channel1 = YansWifiChannelHelper::Default();
    YansWifiPhyHelper phy1;
    phy1.SetChannel(channel1.Create());

    YansWifiChannelHelper channel2 = YansWifiChannelHelper::Default();
    YansWifiPhyHelper phy2;
    phy2.SetChannel(channel2.Create());

    WifiMacHelper mac;
    Ssid ssid1 = Ssid("ns-3-ssid");
    Ssid ssid2 = Ssid("ns-3-ssid");;

    WifiHelper wifi;

    NetDeviceContainer staDevices1, staDevices2;
    mac.SetType("ns3::StaWifiMac", "Ssid", SsidValue(ssid1), "ActiveProbing", BooleanValue(false));
    staDevices1 = wifi.Install(phy1, mac, wifiStaNodes1);
    mac.SetType("ns3::StaWifiMac", "Ssid", SsidValue(ssid2), "ActiveProbing", BooleanValue(false));
    staDevices2 = wifi.Install(phy2, mac, wifiStaNodes2);

    NetDeviceContainer apDevice1, apDevice2;
    mac.SetType("ns3::ApWifiMac", "Ssid", SsidValue(ssid1));
    apDevice1 = wifi.Install(phy1, mac, wifiApNodes.Get(0));
    mac.SetType("ns3::ApWifiMac", "Ssid", SsidValue(ssid2));
    apDevice2 = wifi.Install(phy2, mac, wifiApNodes.Get(1));

    MobilityHelper mobility;

    mobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                  "MinX",
                                  DoubleValue(0.0),
                                  "MinY",
                                  DoubleValue(0.0),
                                  "DeltaX",
                                  DoubleValue(5.0),
                                  "DeltaY",
                                  DoubleValue(10.0),
                                  "GridWidth",
                                  UintegerValue(3),
                                  "LayoutType",
                                  StringValue("RowFirst"));

    mobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel",
                              "Bounds",
                              RectangleValue(Rectangle(-50, 50, -50, 50)));
    mobility.Install(wifiStaNodes1);
    mobility.Install(wifiStaNodes2);

    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(wifiApNodes);

    InternetStackHelper stack;
    stack.Install(p2pNodes);

    
    // Ipv4StaticRoutingHelper staticRoutingHelper;
    // stack.SetRoutingHelper (staticRoutingHelper);
    stack.Install(wifiStaNodes1);
    stack.Install(wifiStaNodes2);
;

    Ipv4AddressHelper address;

    Ipv4InterfaceContainer p2pInterfaces, wifiInterfaces1, wifiInterfaces2;
    
    address.SetBase("10.1.1.0", "255.255.255.0");
    address.Assign(apDevice1);
    wifiInterfaces1 = address.Assign(staDevices1);
    
    address.SetBase("10.1.2.0", "255.255.255.0");
    p2pInterfaces = address.Assign(p2pDevices);
    
    address.SetBase("10.1.3.0", "255.255.255.0");
    address.Assign(apDevice2);
    wifiInterfaces2 = address.Assign(staDevices2);

    
    
    UdpEchoServerHelper echoServer(9);

    ApplicationContainer serverApps = echoServer.Install(wifiStaNodes1.Get(4));
    serverApps.Start(Seconds(1.0));
    serverApps.Stop(Seconds(10.0));

    UdpEchoClientHelper echoClient(wifiInterfaces1.GetAddress(4), 9);
    echoClient.SetAttribute("MaxPackets", UintegerValue(10));
    echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApps1 = echoClient.Install(wifiStaNodes1.Get(2));
    clientApps1.Start(Seconds(2.0));
    clientApps1.Stop(Seconds(10.0));
    
    ApplicationContainer clientApps2 = echoClient.Install(wifiStaNodes2.Get(3));
    clientApps2.Start(Seconds(2.0));
    clientApps2.Stop(Seconds(10.0));




	Ipv4GlobalRoutingHelper::PopulateRoutingTables(); // automatically fills up IP Routing Tables where needed

    // Define a flow monitor object
    Ptr<FlowMonitor> flowMonitor;
    FlowMonitorHelper flowHelper;
    flowMonitor = flowHelper.InstallAll();

    Simulator::Stop(Seconds(10.0));

    // if (tracing)
    // {
    //     phy.SetPcapDataLinkType(WifiPhyHelper::DLT_IEEE802_11_RADIO);
    //     pointToPoint.EnablePcapAll("third");
    //     phy.EnablePcap("third", apDevices.Get(0));
    //     csma.EnablePcap("third", csmaDevices.Get(0), true);
    // }
    
    // Animation
    AnimationInterface anim("third.xml");

    Simulator::Run();
    // Calculate packet delivery ratio and end to end delay and throughput
    uint32_t packetsDelivered = 0;
    uint32_t totalPackets = 0;
    double totalDelay = 0;
    
    
    // Retrive the flow statistics
    FlowMonitor::FlowStatsContainer stats = flowMonitor->GetFlowStats();
    for(auto & it: stats)
    {
      FlowId flowId = it.first;
        std::cout << "Flow " << flowId << std::endl;
        std::cout << " Tx Packets: " << it.second.txPackets << std::endl;
        std::cout << " Tx Bytes: " << it.second.txBytes << std::endl;
        std::cout << " Rx Packets: " << it.second.rxPackets << std::endl;
        std::cout << " Rx Bytes: " << it.second.rxBytes << std::endl;
        
      if(it.second.rxPackets > 0)
      {
        packetsDelivered += it.second.rxPackets;
        totalPackets += it.second.txPackets;
        totalDelay += (it.second.delaySum.ToDouble(ns3::Time::S) / it.second.rxPackets);
      }
    }
    
    double packetDeliveryRatio = (double) packetsDelivered / totalPackets;
    double averageEndToEndDelay = totalDelay / packetsDelivered;
    double throughput = (double) packetsDelivered * 1024 * 8 / (100.0 - 0.0) / 1000000;
    
    // Printing the results
    std::cout << "Packets Delivered Ratio: " << packetDeliveryRatio << std::endl;
    std::cout << "Average End-to-End Delay: " << averageEndToEndDelay << std::endl;
    std::cout << "Throughput: " << throughput << std::endl;
    Simulator::Destroy();

    return 0;
}
