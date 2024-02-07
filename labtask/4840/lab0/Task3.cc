//Id:190041113
#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/netanim-module.h"
using namespace ns3;
NS_LOG_COMPONENT_DEFINE("Tree Topology");
int main(int argc, char* argv[]) {
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);
    Time::SetResolution(Time::NS);
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);  
    NodeContainer nodes;
    nodes.Create(4);       
    InternetStackHelper internet;
    internet.Install(nodes);    
    Ipv4AddressHelper address;
    address.SetBase("192.3.13.0", "255.255.255.0");        
    PointToPointHelper p2p;
    p2p.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    p2p.SetChannelAttribute("Delay", StringValue("2ms"));       
    NetDeviceContainer devices;      
    uint32_t links[5][2] = {{0, 1},{0,2},{1,3},{2,0},{3,1} };
        
    for (uint32_t i = 0; i <= 4; ++i){
    	devices.Add(p2p.Install(nodes.Get(links[i][0]), nodes.Get(links[i][1])));
    }    
    Ipv4InterfaceContainer interfaces = address.Assign(devices);
    UdpEchoServerHelper echoServer(9);       
    uint32_t serverStart = 1.0, serverEnd = 10.0;
    uint32_t clientStart = 2.0, clientEnd = 9.0;
        
    for (uint32_t i = 0; i < 5; ++i) {     
    	uint32_t serverNode = links[i][0], clientNode = links[i][1];       	
    	ApplicationContainer serverApps = echoServer.Install(nodes.Get(serverNode));
    	serverApps.Start(Seconds(serverStart));
    	serverApps.Stop(Seconds(serverEnd));      	
	UdpEchoClientHelper echoClient(interfaces.GetAddress(serverNode), 9);
	echoClient.SetAttribute("MaxPackets", UintegerValue(2));
	echoClient.SetAttribute("Interval", TimeValue(Seconds(2.0)));
	echoClient.SetAttribute("PacketSize", UintegerValue(1024));
    ApplicationContainer clientApps = echoClient.Install(nodes.Get(clientNode));
	clientApps.Start(Seconds(clientStart));
	clientApps.Stop(Seconds(clientEnd));       	
    	serverStart +=10, serverEnd += 10;
    	clientStart +=10, clientEnd += 10;
    }
    // AnimationInterface anim("task03.xml");
    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
