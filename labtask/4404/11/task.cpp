#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;

int bellmanFord(vector<pii> List[], int N, int E)
{
    int src = 1;
    int dis[N];
    for (int i = 0; i < N; i++)
        dis[i] = INF;
    dis[src] = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = i;
            int v = List[u][j].second;
            int weight = List[u][j].first;
            if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
                dis[v] = dis[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = N;
        int v = List[u][i].second;
        int weight = List[u][i].first;
        if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
        {
            //printf("Graph contains negative weight cycle");
            return -1;
        }
    }
    return dis[N];
}

int main()
{
    int N, V;
    cin >> N >> V;
    int fg[N];
    for (int i = 0; i < N - 1; i++)
        cin >> fg[i];
    vector<pii> List[N];
    fg[N] = 0;
    for (int i = 0; i < V; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        List[from].push_back(make_pair(weight - fg[to], to));
        int ans = bellmanFord(List, N, V);
        cout<<ans;
    }
}
