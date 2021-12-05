#include <bits/stdc++.h>
using namespace std;

int mat[1001][1001];
int cost[1001];

void bfs(int s, int V)
{
    bool visit[V];
    for (int i = 0; i < V; i++)
        visit[i] = false;
    queue<int> q;

    q.push(s);
    visit[s] = true;
    while (!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (int i = 0; i < V; i++)
        {
            if ((mat[s][i] == 1) && (!visit[i]))
            {
                q.push(i);
                visit[i] = true;
            }
        }
    }
}

int main()
{
    int q, V, E, u, v, S;
    while (q--)
    {
        cin >> V >> E;
        for (int l = 0; l < E; l++)
        {
            cin >> u >> v;
            mat[u][v] = 1;
            mat[v][u] = 1;
        }
        cin >> S;
        bfs(S, V);
    }
}
