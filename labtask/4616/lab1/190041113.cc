#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/netanim-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
using namespace ns3;

NS_LOG_COMPONENT_DEFINE("190041113");

int
main(int argc, char* argv[])
{
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    Time::SetResolution(Time::NS);
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    NodeContainer nc;
    nc.Create(3);

    PointToPointHelper pointToPoint;
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));

    // NodeContainer n1, n2, n3;
    // n1.add(node.Get(0),node.Get(1));
    //  n2.add(node.Get(1),node.Get(2));
    // n3.add(node.Get(2),node.Get(3));
    //

    // n1.Create(2);
    // n2.Create(2);

    NetDeviceContainer d1, d2, d3;
    d1 = pointToPoint.Install(nc.Get(0), nc.Get(1));
    d2 = pointToPoint.Install(nc.Get(1), nc.Get(2));
    d3 = pointToPoint.Install(nc.Get(2), nc.Get(0));

    InternetStackHelper stack;
    stack.Install(nc);

    Ipv4AddressHelper address; //, address2, address3;
    address.SetBase("10.1.1.0", "255.255.255.0");
    // address1.SetBase("10.1.1.0", "255.255.255.0");
    // address2.SetBase("10.1.2.0", "255.255.255.0");
    // address3.SetBase("10.1.3.0", "255.255.255.0");

    Ipv4InterfaceContainer interface1 = address.Assign(d1);
    Ipv4InterfaceContainer interface2 = address.Assign(d2);
    Ipv4InterfaceContainer interface3 = address.Assign(d3);

    UdpEchoServerHelper echoServer(9);

    ApplicationContainer serverApp1 = echoServer.Install(nc.Get(1));
    serverApp1.Start(Seconds(1.0));
    serverApp1.Stop(Seconds(10.0));

    UdpEchoClientHelper echoClient1(interface1.GetAddress(1), 9);
    echoClient1.SetAttribute("MaxPackets", UintegerValue(100));
    echoClient1.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient1.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApp1 = echoClient1.Install(nc.Get(0));
    clientApp1.Start(Seconds(2.0));
    clientApp1.Stop(Seconds(10.0));

    ApplicationContainer serverApp2 = echoServer.Install(nc.Get(2));
    serverApp2.Start(Seconds(1.0));
    serverApp2.Stop(Seconds(10.0));

    UdpEchoClientHelper echoClient2(interface2.GetAddress(1), 9);
    echoClient2.SetAttribute("MaxPackets", UintegerValue(100));
    echoClient2.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient2.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApp2 = echoClient2.Install(nc.Get(1));
    clientApp2.Start(Seconds(2.0));
    clientApp2.Stop(Seconds(10.0));

    ApplicationContainer serverApp3 = echoServer.Install(nc.Get(0));
    serverApp3.Start(Seconds(1.0));
    serverApp3.Stop(Seconds(10.0));

    UdpEchoClientHelper echoClient3(interface3.GetAddress(1), 9);
    echoClient3.SetAttribute("MaxPackets", UintegerValue(100));
    echoClient3.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient3.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApp3 = echoClient3.Install(nc.Get(2));
    clientApp3.Start(Seconds(2.0));
    clientApp3.Stop(Seconds(10.0));

    AnimationInterface anim("190041113_2.xml");

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
