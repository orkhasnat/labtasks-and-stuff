#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int latency[100001];
vector<vector<pair<int, int>>> adj;
#define INF 2147483647
void dijkstra(int n, int s)
{
    for (int i = 0; i < n; i++)
        latency[i] = INF;
    latency[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(pair<int, int>(latency[s], s));
    pair<int, int> p;
    int t, u;
    while (!Q.empty())
    {
        p = Q.top();
        Q.pop();
        t = p.first;
        u = p.second;
        if (t > latency[u])
            continue;
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (latency[adj[u][i].first] > latency[u] + adj[u][i].second)
            {
                latency[adj[u][i].first] = latency[u] + adj[u][i].second;
                Q.push(pair<int, int>(latency[adj[u][i].first], adj[u][i].first));
            }
        }
    }
}

int main()
{
    int N, n, m, S, T;
    cin >> N;
    for (int k = 1; k <= N; k++)
    {
        cin >> n >> m >> S >> T;
        adj.assign(n, vector<pair<int, int>>(0));
        int x, y, w;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> w;
            adj[x].push_back(pair<int, int>(y, w));
            adj[y].push_back(pair<int, int>(x, w));
        }
        dijkstra(n, S);
        cout << "Case #" << k << ": ";
        if (latency[T] != INF)
            printf("%d\n", latency[T]);
        else
            printf("unreachable\n");
    }
}