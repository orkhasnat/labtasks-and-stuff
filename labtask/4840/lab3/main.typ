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
  date: "April 02, 2024",
  logo: "iut.png",
)
// #show heading: it=>[#set align(center,it.body)]
#set page(numbering: "1", number-align: center)
#counter(page).update(1)

= Objective
Understanding the impact of different MANET routing protocols in different mobility situations.

#pagebreak()
= Understanding different routing protocols

=== OLSR (Optimized Link State Routing)
- OLSR is a proactive routing protocol designed for mobile ad hoc networks (MANETs).
- It maintains a routing table with the latest topology information by periodically exchanging link state information with neighboring nodes.
- OLSR optimizes the network resources by selecting multiple routes to each destination, thus improving reliability and load balancing.
- It reduces control overhead by using MultiPoint Relays (MPRs) to broadcast routing information selectively, rather than flooding it to all nodes.

=== AODV (Ad Hoc On-Demand Distance Vector)
- AODV is a reactive routing protocol designed for MANETs.
- It establishes routes on-demand as needed, rather than maintaining a complete routing table.
- Route discovery is initiated by broadcasting route request (RREQ) packets when a node needs to communicate with a destination.
- Intermediate nodes forward the RREQ and set up reverse routes to the source to facilitate route replies (RREP).
- AODV employs sequence numbers to ensure the freshness of routing information and to prevent the formation of routing loops.
- Routes are maintained as long as they are being used, and they are updated only when there are changes in the network topology or link conditions.


=== DSDV (Destination-Sequenced Distance Vector)
- DSDV is a proactive routing protocol based on the traditional distance vector algorithm.
- Each node maintains a routing table with entries for all possible destinations along with associated sequence numbers.
- Updates are sent periodically or when there is a change in the network topology.
- DSDV prevents routing loops by using sequence numbers to ensure the freshness of routing information.
- It is less efficient in highly dynamic networks due to its frequent update exchanges and potential for route oscillations

=== DSR (Dynamic Source Routing)
- DSR is a reactive routing protocol suitable for MANETs.
- It relies on the source node to discover and maintain routes to the destination on-demand.
- When a node needs to send data to a destination, it initiates a route discovery process by broadcasting a route request (RREQ) packet.
- Intermediate nodes forward the RREQ until it reaches the destination or a node with a route to the destination.
- Route reply (RREP) packets are sent back to the source node through the reverse path discovered during route discovery.
- DSR supports route caching, allowing intermediate nodes to store discovered routes for future use, thereby reducing overhead for subsequent transmissions to the same destination.

#pagebreak()
= Understanding different Mobility Models

=== Random Way Point

- The Random Waypoint model is a widely used mobility model in the simulation of mobile ad hoc networks (MANETs) and wireless sensor networks (WSNs).
- In this model, each node randomly selects a destination within the simulation area and moves towards it at a constant speed.
- Upon reaching the destination, the node pauses for a certain amount of time before selecting a new random destination and repeating the process.
- The pause time between movements and the speed of the nodes are typically specified as parameters in the simulation.
- This model assumes independent node movements and does not consider factors such as node density or communication patterns.

=== Random Walk

- The Random Walk model is a simple mobility model used to simulate the movement of entities in various applications, including network simulations.
- In this model, nodes move randomly in the simulation area by taking successive steps in random directions.
- The direction and length of each step are determined by random processes, such as uniformly distributed angles and speeds.
- Nodes may change direction and speed at each step independently of their previous movements.
- Random Walk models are often used to study diffusion processes, search algorithms, and other phenomena that involve random movement.

=== Reference Point Group Mobility
- The Reference Point Group Mobility (RPGM) model is a mobility model that captures the movement patterns of groups of mobile nodes in wireless networks.
- In this model, nodes are organized into groups, with each group having a reference point that represents the center of mass or the leader node.
- Nodes within a group move together towards the reference point, simulating coordinated movement behavior.
- The reference points may move according to predefined mobility patterns, such as random waypoint or random walk, or they may follow specific trajectories.
- RPGM is useful for studying scenarios where nodes exhibit group behavior, such as in vehicular adhoc networks (VANETs), flocking simulations, or collaborative sensing applications.
- This model enables researchers to analyze the impact of group dynamics on network performance, such as group formation, disbandment, and collective decision-making.

#pagebreak()

= Experimental Setup
The network topology consists of 50 wireless nodes (WiFi devices) deployed in a 2D space. Each node is
equipped with a WiFi interface and is capable of communicating with other nodes within its transmission
range. The nodes move randomly within the specified bounds (0 to 300 in the x-direction and 0 to 1500 in
the y-direction) with a speed ranging from 0 to 20 m/s.

The communication among nodes is facilitated by the specified routing protocol (e.g., OLSR, AODV, DSDV,
DSR). Each node can act as a source (transmitter) or destination (receiver) of packets, and the communica-
tion pattern is determined by the OnOff application model, which generates traffic between nodes.

The SetupPacketReceive function sets up a socket in each sink node to receive packets, while the Re-
ceivePacket function handles the reception of packets. The CheckThroughput function calculates the through-
put of received packets over time and writes the results to a CSV file.

#figure(
  image("image1.png"),
  caption: [Random Way Point]
)
#figure(
  image("image.png"),
  caption: [Random Walk]
)

#pagebreak()

#v(30pt)
#figure(
table(
  columns: 5,
  table.header(
    "Mobility Model","OLSR","AODV","DSDV","DSR"
  ),
  [Random Way Point],[4.79744],[10.40896],[4.7616],[7.51104],
  [Random Walk],[10.81344],[11.89888],[11.06432],[10.0608],
  stroke : 2pt,
  gutter: 3pt,
  align: left,
  
),caption:[Average Receive Rate of different routing protocols on different mobility models]
)
#v(30pt)
= Conclusion
For random way point mobility model reactive MANET routing protocols are better as our network is highly
dynamic and the nodes change positions frequently. So, logically DSR & AODV performed better. But,
because of route discovery overhead & route maintenance overhead AODV is slighly better than DSR.

For random walk mobility model all the routing algorithm kind of gives same result. As random walk
is highly unpredictable and ranodm, the routing overhead is similar for all the routing protocols. Also, there
is a little chance of optimization and lack of correlation makes the network work similar on all of them.