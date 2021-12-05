#include <bits/stdc++.h>
using namespace std;
int vertices = 5;
int mat[5][5] =
    {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };


void bfs(int s)
{
    bool visit[vertices];
    for (int i = 0; i < vertices; i++)
        visit[i] = false;
    queue<int> q;

    q.push(s);
    visit[s]= true;
    while(!q.empty())
    {
        s=q.front();
        cout<<s<<" ";
        q.pop();

        for(int i= 0; i<vertices; i++)
        {
            if((mat[s][i]==1)
                &&(!visit[i]))
            {
                q.push(i);
                visit[i]=true;
            }
        }
    }
}

int main()
{
    bfs(2);
}
