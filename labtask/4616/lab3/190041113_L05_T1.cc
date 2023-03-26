#include "ns3/core-module.h"
#include "ns3/wifi-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
#include "ns3/flow-monitor-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("AdhocNetworkExample");

int main (int argc, char *argv[])
{
  LogComponentEnable ("AdhocNetworkExample", LOG_LEVEL_INFO);  //see logs in console
  //LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
  //LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

  // Create two wireless nodes
  NodeContainer nodes, n1_5, n6_10, n1_3, n4_7, n8_10;
  nodes.Create (10);
  n1_5.Add(nodes.Get(0));
  n1_5.Add(nodes.Get(1));
  n1_5.Add(nodes.Get(2));
  n1_5.Add(nodes.Get(3));
  n1_5.Add(nodes.Get(4));
  n6_10.Add(nodes.Get(5));
  n6_10.Add(nodes.Get(6));
  n6_10.Add(nodes.Get(7));
  n6_10.Add(nodes.Get(8));
  n6_10.Add(nodes.Get(9));
  n1_3.Add(nodes.Get(0));
  n1_3.Add(nodes.Get(1));
  n1_3.Add(nodes.Get(2));
  n4_7.Add(nodes.Get(3));
  n4_7.Add(nodes.Get(4));
  n4_7.Add(nodes.Get(5));
  n4_7.Add(nodes.Get(6));
  n8_10.Add(nodes.Get(7));
  n8_10.Add(nodes.Get(8));
  n8_10.Add(nodes.Get(9));

  // Configure wireless parameters
  WifiHelper wifi;

  WifiMacHelper mac;
  mac.SetType ("ns3::AdhocWifiMac");

  YansWifiChannelHelper channel = YansWifiChannelHelper::Default();
  YansWifiPhyHelper phy;
  phy.SetChannel(channel.Create());
  phy.Set("TxPowerStart", DoubleValue(10.0));
  phy.Set("TxPowerEnd", DoubleValue(10.0));
  phy.Set("TxGain", DoubleValue(0.0));
  phy.Set("RxGain", DoubleValue(0.0));

  

  NetDeviceContainer devices;
  devices.Add(wifi.Install (phy, mac, n1_3));

  phy.SetChannel(channel.Create());
  phy.Set("TxPowerStart", DoubleValue(15.0));
  phy.Set("TxPowerEnd", DoubleValue(15.0));
  phy.Set("TxGain", DoubleValue(0.0));
  phy.Set("RxGain", DoubleValue(0.0));
  devices.Add(wifi.Install (phy, mac, n4_7));

  phy.SetChannel(channel.Create());
  phy.Set("TxPowerStart", DoubleValue(20.0));
  phy.Set("TxPowerEnd", DoubleValue(20.0));
  phy.Set("TxGain", DoubleValue(0.0));
  phy.Set("RxGain", DoubleValue(0.0));
  devices.Add(wifi.Install (phy, mac, n8_10));


  // Set up mobility model
  MobilityHelper mobility;
  mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
                                 "MinX", DoubleValue (0.0),
                                 "MinY", DoubleValue (0.0),
                                 "DeltaX", DoubleValue (25.0),
                                 "DeltaY", DoubleValue (15.0),
                                 "GridWidth", UintegerValue (3),
                                 "LayoutType", StringValue ("RowFirst"));
                                 
                                
  mobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel", "Bounds", RectangleValue(Rectangle(-50, 50, -50, 50)));
  mobility.Install (n1_5);

  mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
                                 "MinX", DoubleValue (50.0),
                                 "MinY", DoubleValue (50.0),
                                 "DeltaX", DoubleValue (25.0),
                                 "DeltaY", DoubleValue (15.0),
                                 "GridWidth", UintegerValue (3),
                                 "LayoutType", StringValue ("RowFirst"));
                                 
                                
  mobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel", "Bounds", RectangleValue(Rectangle(-100, 100, -100, 100)));
  mobility.Install (n6_10);
  

  // Set up network stack
  InternetStackHelper stack;
  stack.Install (nodes);

  // Assign IPv4 addresses
  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");
  // address.Assign (devices4_7);
  // address.Assign (devices8_10);
  Ipv4InterfaceContainer interfaces = address.Assign (devices);

  // Create a UDP echo server application on node 1
  uint16_t port = 9; // well-known echo port number
  UdpEchoServerHelper server (port);
  ApplicationContainer serverApps = server.Install (nodes.Get (1));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (20.0));

  // Create a UDP echo client application on node 0
  UdpEchoClientHelper client (interfaces.GetAddress (1), port);
  client.SetAttribute ("MaxPackets", UintegerValue (100));
  client.SetAttribute ("Interval", TimeValue (Seconds (0.5)));
  client.SetAttribute ("PacketSize", UintegerValue (1024));
  
  ApplicationContainer clientApps = client.Install (nodes.Get (0));
  clientApps.Start (Seconds (2.0));
  clientApps.Stop (Seconds (20.0));
  
  // Define a flow monitor object
  Ptr<FlowMonitor> flowMonitor;
  FlowMonitorHelper flowHelper;
  flowMonitor = flowHelper.InstallAll();
 
  
  
  Simulator::Stop(Seconds(20.0));
  
  
  // Animation
  AnimationInterface anim("two_wireless_nodes.xml");

  // Enable packet tracing
  phy.EnablePcapAll ("adhoc-network");

  // Run simulation
  Simulator::Run ();
  
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
  
  Simulator::Destroy ();

  return 0;
}
