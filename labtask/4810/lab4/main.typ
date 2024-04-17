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
  align(center,text(1.5em,"CSE 4810"))
  align(center,text(1.5em,"Algorithm Engineering Lab"))
  line(length: 100%)
  align(center,text(2.0em, weight: 700, title))
  line(length: 100%)
  
  
  // v(1.2em, weak: true)
  align(center,  text(2em, "Tasnimul Hasnat"))
  align(center,  text(1.5em, "190041113"))
  align(center,  text(1.5em, "CSE 1A"))
  align(center,  text(1.5em, date))
  
  

  

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
  date: "April 17, 2024",
  logo: "iut.png",
)
// #show heading: it=>[#set align(center,it.body)]
#set page(numbering: "1", number-align: center)
#counter(page).update(1)

Two tasks were given, solved them in Leetcode.


= Task 1

```python
class Solution:
    def findTheCity(self, N, edges, distanceThreshold):
        Graph = defaultdict(list)
        for u, v, w in edges:
            Graph[u].append([v, w])
            Graph[v].append([u, w])

        def dijkstra(i):
            pq = []
            heappush(pq, [0, i])
            path = [inf] * N
            path[i] = 0 
            
            while pq:
                dist, node = heappop(pq)
                if dist > distanceThreshold:
                    break
                for nei, w in Graph[node]:
                    if dist + w < path[nei]:
                        path[nei] = dist + w
                        heappush(pq, [path[nei], nei])
            
            cnt = -1 
            for i in range(N):
                cnt += path[i] <= distanceThreshold
            return cnt

        cnts = {}
        mini, maxi = N + 1, 0
        for i in range(N):
            cnts[i] = dijkstra(i)
            mini = min(cnts[i], mini)
            if cnts[i] == mini:
                maxi = max(maxi, i)
        return maxi
```

#pagebreak()

= Task 2

```python
class Solution:
    def minCostConnectPoints(self, points):
        distances = [[0, 0]] + [[float('inf'), i] for i in range(1, len(points))]
        result = 0
        while distances:
            closest = min(distances)
            result += closest[0]
            x, y = points[closest[1]]

            closest[:] = distances[-1][:]
            distances.pop()

            for dist in distances:
                x2, y2 = points[dist[1]]
                dist[0] = min(dist[0], abs(x - x2) + abs(y - y2))
        return result

```