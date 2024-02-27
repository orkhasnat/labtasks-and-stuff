#let project(title: "", date: none, logo: none, body) = {
  set document(title: title)
  set page(paper: "a4")
  set text(font: "Merriweather", lang: "en")
  show math.equation: set text(weight: 400)

  // Set paragraph spacing.
  show par: set block(above: 1.4em, below: 1.3em)

  // set heading(numbering: "1.1")
  set par(leading: 0.75em)

  // Title page.
  // The page can contain a logo if you pass one with `logo: "logo.png"`.
  v(0.6fr)
  if logo != none {
    align(center, image(logo, width: 40%))
  }
  align(center,text(2em, "Islamic University of Technology",weight: "bold"))
  align(center,text(1.5em,"CSE 4840"))
  align(center,text(1.5em,"Internetworking Protocols Lab"))
  line(length: 100%)
  align(center,text(2.0em, weight: 700, title))
  line(length: 100%)
  
  
  // v(1.2em, weak: true)
  align(center,  text(2em, "Tasnimul Hasnat"))
  align(center,  text(1.5em, "190041113"))
  align(center,  text(1.5em, "CSE 1A"))
  align(center,  text(1.5em, date))
  
   set raw(theme: "halcyon.tmTheme")
    show raw.where(block:true): it => block(
      width: 100%,
      fill: rgb("#1d2433"),
      inset: (left:40pt,top:20pt,bottom:20pt,right:20pt),
      radius: 10pt,
      text(fill: rgb("#a2aabc"), it)
  )

  

  // v(2.4fr)
  pagebreak()

  // Main body.
  set par(justify: true)
  set text(hyphenate: false)

  body
  // pagebreak()
}

#show: project.with(
  title: "Lab 3",
  date: "February 27, 2024",
  logo: "iut.png",
)
// #show heading: it=>[#set align(center,it.body)]
#set page(numbering: "1", number-align: center)
#counter(page).update(1)

= Objective
Configure RIP routing protocols for a given network topology using ns-3. Monitor the
routing tables at specified time intervals and observe the impact of link teardown events.

#image("image.png")

\
= Code
```cpp

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
    
```
#pagebreak()
```cpp
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

```
#pagebreak()
= Result

=== At 20 seconds
```
Node: 4, Time: +20s, Local time: +20s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 4, Time: +20s, Local time: +20s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.7.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.8.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.10.0       10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.9.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.6.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.5.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.4.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.0.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.1.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.2.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.3.0        0.0.0.0         255.255.255.0   U     1      -      -   4

Node: 5, Time: +20s, Local time: +20s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 5, Time: +20s, Local time: +20s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.2.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.1.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.0.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.9.0        10.0.5.2        255.255.255.0   UGS   2      -      -   3
10.0.10.0       10.0.6.2        255.255.255.0   UGS   2      -      -   4
10.0.8.0        10.0.4.2        255.255.255.0   UGS   2      -      -   2
10.0.7.0        10.0.4.2        255.255.255.0   UGS   2      -      -   2
10.0.3.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.4.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.5.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.6.0        0.0.0.0         255.255.255.0   U     1      -      -   4

Node: 6, Time: +20s, Local time: +20s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 6, Time: +20s, Local time: +20s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.10.0       10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.9.0        10.0.7.2        255.255.255.0   UGS   2      -      -   2
10.0.6.0        10.0.4.1        255.255.255.0   UGS   2      -      -   1
10.0.3.0        10.0.4.1        255.255.255.0   UGS   2      -      -   1
10.0.5.0        10.0.7.2        255.255.255.0   UGS   2      -      -   2
10.0.4.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.7.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.8.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 7, Time: +20s, Local time: +20s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 7, Time: +20s, Local time: +20s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.4.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.3.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.10.0       10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.8.0        10.0.7.1        255.255.255.0   UGS   2      -      -   2
10.0.6.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.5.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.7.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.9.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 8, Time: +20s, Local time: +20s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 8, Time: +20s, Local time: +20s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.6.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.6.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.6.1        255.255.255.0   UGS   3      -      -   1
10.0.7.0        10.0.9.1        255.255.255.0   UGS   2      -      -   3
10.0.5.0        10.0.6.1        255.255.255.0   UGS   2      -      -   1
10.0.4.0        10.0.6.1        255.255.255.0   UGS   2      -      -   1
10.0.3.0        10.0.6.1        255.255.255.0   UGS   2      -      -   1
10.0.6.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.8.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.9.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.10.0       0.0.0.0         255.255.255.0   U     1      -      -   4
```
\
=== At 40 seconds
```
Node: 4, Time: +40s, Local time: +40s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 4, Time: +40s, Local time: +40s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.7.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.8.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.9.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.5.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.4.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.0.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.1.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.2.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.3.0        0.0.0.0         255.255.255.0   U     1      -      -   4

Node: 5, Time: +40s, Local time: +40s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 5, Time: +40s, Local time: +40s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.2.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.1.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.0.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.9.0        10.0.5.2        255.255.255.0   UGS   2      -      -   3
10.0.8.0        10.0.4.2        255.255.255.0   UGS   2      -      -   2
10.0.7.0        10.0.4.2        255.255.255.0   UGS   2      -      -   2
10.0.3.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.4.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.5.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 6, Time: +40s, Local time: +40s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 6, Time: +40s, Local time: +40s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.9.0        10.0.7.2        255.255.255.0   UGS   2      -      -   2
10.0.3.0        10.0.4.1        255.255.255.0   UGS   2      -      -   1
10.0.5.0        10.0.7.2        255.255.255.0   UGS   2      -      -   2
10.0.4.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.7.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.8.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 7, Time: +40s, Local time: +40s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 7, Time: +40s, Local time: +40s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.4.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.3.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.8.0        10.0.7.1        255.255.255.0   UGS   2      -      -   2
10.0.5.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.7.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.9.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 8, Time: +40s, Local time: +40s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 8, Time: +40s, Local time: +40s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.1.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.2.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.7.0        10.0.9.1        255.255.255.0   UGS   2      -      -   3
10.0.5.0        10.0.9.1        255.255.255.0   UGS   2      -      -   3
10.0.4.0        10.0.9.1        255.255.255.0   UGS   3      -      -   3
10.0.3.0        10.0.9.1        255.255.255.0   UGS   3      -      -   3
10.0.8.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.9.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.10.0       0.0.0.0         255.255.255.0   U     1      -      -   4
```
\
=== At 60 seconds
```
Node: 4, Time: +60s, Local time: +60s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 4, Time: +60s, Local time: +60s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.8.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.9.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.5.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.4.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.0.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.1.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.2.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.3.0        0.0.0.0         255.255.255.0   U     1      -      -   4

Node: 5, Time: +60s, Local time: +60s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 5, Time: +60s, Local time: +60s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.2.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.1.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.0.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.9.0        10.0.5.2        255.255.255.0   UGS   2      -      -   3
10.0.8.0        10.0.4.2        255.255.255.0   UGS   2      -      -   2
10.0.3.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.4.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.5.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 6, Time: +60s, Local time: +60s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 6, Time: +60s, Local time: +60s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.3.0        10.0.4.1        255.255.255.0   UGS   2      -      -   1
10.0.4.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.8.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 7, Time: +60s, Local time: +60s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 7, Time: +60s, Local time: +60s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.4.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.3.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.5.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.9.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 8, Time: +60s, Local time: +60s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 8, Time: +60s, Local time: +60s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.1.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.2.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.5.0        10.0.9.1        255.255.255.0   UGS   2      -      -   3
10.0.4.0        10.0.8.1        255.255.255.0   UGS   2      -      -   2
10.0.3.0        10.0.9.1        255.255.255.0   UGS   3      -      -   3
10.0.8.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.9.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.10.0       0.0.0.0         255.255.255.0   U     1      -      -   4
```
\
\
\
\
=== At 80 seconds

```
Node: 4, Time: +80s, Local time: +80s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 4, Time: +80s, Local time: +80s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.8.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.10.0       10.0.3.2        255.255.255.0   UGS   8      -      -   4
10.0.9.0        10.0.3.2        255.255.255.0   UGS   3      -      -   4
10.0.5.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.4.0        10.0.3.2        255.255.255.0   UGS   2      -      -   4
10.0.0.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.1.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.2.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.3.0        0.0.0.0         255.255.255.0   U     1      -      -   4

Node: 5, Time: +80s, Local time: +80s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 5, Time: +80s, Local time: +80s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.2.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.1.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.0.0        10.0.3.1        255.255.255.0   UGS   2      -      -   1
10.0.9.0        10.0.5.2        255.255.255.0   UGS   2      -      -   3
10.0.10.0       10.0.4.2        255.255.255.0   UGS   7      -      -   2
10.0.8.0        10.0.4.2        255.255.255.0   UGS   2      -      -   2
10.0.3.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.4.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.5.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.6.0        10.0.3.1        255.255.255.0   UGS   16     -      -   1

Node: 6, Time: +80s, Local time: +80s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 6, Time: +80s, Local time: +80s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.10.0       10.0.8.2        255.255.255.0   UGS   6      -      -   3
10.0.9.0        10.0.4.1        255.255.255.0   UGS   3      -      -   1
10.0.3.0        10.0.4.1        255.255.255.0   UGS   2      -      -   1
10.0.5.0        10.0.4.1        255.255.255.0   UGS   2      -      -   1
10.0.4.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.8.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 7, Time: +80s, Local time: +80s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 7, Time: +80s, Local time: +80s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.1.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.2.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.4.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.3.0        10.0.5.1        255.255.255.0   UGS   2      -      -   1
10.0.10.0       10.0.5.1        255.255.255.0   UGS   8      -      -   1
10.0.8.0        10.0.5.1        255.255.255.0   UGS   3      -      -   1
10.0.6.0        10.0.9.2        255.255.255.0   UGS   16     -      -   3
10.0.5.0        0.0.0.0         255.255.255.0   U     1      -      -   1
10.0.9.0        0.0.0.0         255.255.255.0   U     1      -      -   3

Node: 8, Time: +80s, Local time: +80s, Ipv4ListRouting table
  Priority: 0 Protocol: ns3::Rip
Node: 8, Time: +80s, Local time: +80s, IPv4 RIP table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
10.0.0.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.1.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.2.0        10.0.9.1        255.255.255.0   UGS   4      -      -   3
10.0.5.0        10.0.9.1        255.255.255.0   UGS   2      -      -   3
10.0.4.0        10.0.8.1        255.255.255.0   UGS   2      -      -   2
10.0.3.0        10.0.9.1        255.255.255.0   UGS   3      -      -   3
10.0.8.0        0.0.0.0         255.255.255.0   U     1      -      -   2
10.0.9.0        0.0.0.0         255.255.255.0   U     1      -      -   3
10.0.10.0       0.0.0.0         255.255.255.0   U     1      -      -   4
```
