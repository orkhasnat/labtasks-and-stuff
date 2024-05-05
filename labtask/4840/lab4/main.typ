#let project(title: "", date: none, logo: none, body) = {
  set document(title: title)
  set page(paper: "a4")
  set text(font: "Atkinson Hyperlegible", lang: "en")
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
  title: "Lab 4",
  date: "May 06, 2024",
  logo: "iut.png",
)
// #show heading: it=>[#set align(center,it.body)]
#set page(numbering: "1", number-align: center)
#counter(page).update(1)

= Introduction
Using the ns-3 network simulator, the report explores various routing protocols in great
detail. It describes in great detail the precise configurations that were used, the minute
details of how each protocol was put into practice, and it performs a thorough analysis to
compare how well each protocol performed in the simulated environment under controlled
conditions.

= `Ns3` "routing" directory’s routing protocols
The following files are located in the ns3/examples/routing/ folder; each demon- com-
paring the various routing protocols that are employed in NS-3 simulations:

1. Dynamic Global Routing
  - dynamic-global-routing.cc
2. Global Routing:
  - global-injection-slash32.cc
  - global-routing-multi-switch-plus-router.cc
  - global-routing-slash32.cc
  - mixed-global-routing.cc
  - simple-global-routing.cc
3. RIP/RIPng (Routing Information Protocol/next generation):
  - rip-simple-network.cc
  - ripng-simple-network.cc
4. Simple Alternate Routing
  - simple-alternate-routing.cc
5. Static Routing:
  - static-routing-slash32.cc
6. MANET (Mobile Ad-hoc Network) Routing:
  - manet-routing-compare.cc
7. Multicast Routing:
  - simple-multicast-flooding.cc
8. IPv6 Routing:
  - simple-routing-ping6.cc
  - simple-routing-ping6.py

For Comparison, we will choose: rip-simple-network.cc, ripng-simple-network.cc, simple-
global-routing.cc, static-routing-slash32.cc, dynamic-global-routing.cc and manet-comparison.cc
  
#pagebreak()
= Exploring Routing Protocols

== Proactive Routing with Global Insight

*Overview*: This approach leverages a global understanding of the network to proactively
manage and update routing tables, typically employing algorithms like Shortest Path
First (SPF).

*Applicability*: Effective in stable, wired networks with infrequent changes.

*Advantages*: Efficient for networks with static or seldom changing topologies.

*Drawbacks*: Not suited for dynamic or large-scale networks due to scalability and
adaptability limitations.

== Distance-Vector Routing: The Essence of RIP
*Overview*: RIP utilizes a Distance-Vector algorithm to determine the shortest path to
each network node based on hop count, capped at 15 hops.

*Suitability*: Ideal for smaller, less complex networks requiring straightforward rout-
ing solutions.

*Strengths*: Easy to configure and understand.

*Weaknesses*: Limited scalability due to the 15-hop constraint and slow convergence
in dynamic environments


== RIPng: Navigating IPv6 Networks

*Overview*: Tailored for IPv6 networks, RIPng employs a Distance-Vector algorithm with
a 15-hop limit.

*Use Cases:* Well-suited for small to medium-sized IPv6 networks requiring simple
routing solutions.

*Advantages*: Offers straightforward configuration, easy comprehension, and IPv6
compatibility.

*Limitations*: Restricted scalability is due to the 15-hop constraint and slow convergence times, making it less suitable for larger or highly dynamic networks.

#pagebreak()
= Performance Analysis

Medium-sized to Small-sized Networks For modestly sized to medium-sized networks with
generally stable topologies and RIP, RIPng, or traffic could all be good choices. They provide easy configuration. RIPng is chosen for IPv6 networks due to its superior stability, robustness, and measures of performance. Five Huge Networks Dynamic Global Scalability is important in larger networks where it It might be better to use routing. Even though its throughput might be lower, its capacity to routing paths can be optimized by dynamically adjusting to shifting network conditions. and strengthen resilience. Consistent Wirenet Systems Robust wired networks have Simple Global Routing as a serious
competitor. It is It is perfect in situations where there is an efficient throughput and consistent performance. The topology of a network seldom changes. Differentiated Network
Environments In the case of networks with diverse requirements spanning various segments or regions, The use of mixed global routing could offer a compromise between dynamic flexibility. Nonetheless, cautious setup and administration are required. in order
to reduce any potential complexity. Particular Uses In particular applications where very
consistent performance and minimal latency are needed, Industrial control networks or
real-time communication systems, for instance, Low latency and simplicity are two advantages of static routing. Still, though, it Perhaps not suitable for large-scale or dynamic deployments.
#v(30pt)
#figure(
table(
  columns: 3,
  table.header(
    "Routing Protocol","Average Delay (s)","Throughput (Kbps)"
  ),
  [RIP],[0.0056 - 0.015],[47.85 - 187.56],
  [RIPng],[0.0023 - 0.0119],[Up to 828.607],
  [Simple Global],[0.0158],[Approx. 482],
  [Dynamic Global],[0.0021 - 0.015],[1.74 - 3.43],
  [Mixed Global],[0.0168],[0.56],
  [Static Routing],[0.0057],[6.85],
  stroke : 1pt,
  gutter: 3pt,
  align: center
),caption:[Routing Protocol Performance]
)
#v(30pt)

// #pagebreak()

= Conclusion
Performance assessment in ns-3 highlights the various aspects and trade-offs present in
various routing protocols. Understanding these nuances is crucial to selecting the best
protocol for a given network scenario, considering variables like network size, stability,
scalability, and performance requirements. With the help of these insights, network
engineers and administrators can create robust and efficient communication frameworks
by making informed decisions.
