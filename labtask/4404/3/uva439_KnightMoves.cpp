#include <bits/stdc++.h>
#define INF 9999;
using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int cost[8][8];

//This function calculates the next possible location for knight
//First parameter denotes the current position
//Second parameter denotes the iteration number, which is used to calculate position
string getPosition(string pos, int i)
{
    string newpos = pos;
    newpos[0] += dx[i];
    newpos[1] += dy[i];

    return newpos;
}
bool invalid(string & s){
    if(s[0]<'a' && s[0]>'h' && s[1]<'1' && s[1]>'8')
        return true;
    return false;
}

int bfs(string src, string dst)
{
    queue<pair<int, int>> q;
    pair<int, int> p,q;
    p.first = src[0] - 'a';
    p.second = src[1] - '1';
    q.first= des[0]- 'a';
    q.second = des[1]-'1';
    int visited[8];
    memset(visited,0);
    cost[p.first][p.second];
    q.push(p);
    visited[]
    while(!q.empty())
    {
        p= q.front();
        q.pop();
        if(p==q)
            return;

        for(int i=0;i<8;i++){
            string newpos= getPosition(src,i);
            if(!invalid(newpose))
                q.push(make_pair(newpose[0]-'a',newpose[1]-'1'));

        }



    }
    //Run a loop as long the queue is not empty
    //Get the front value of queue and remove it from the queue
    //If the removed value matches destination stop the loop and return the cost
    //else calculate 8 possible new position for the knight
    //validate the new position.
    //If new position is invalid get the next position
    //Else check whether that position is already visited or not,
    //If not visited, push it to the queue and update its cost

    //return infinite cost, if queue becomes empty, still didnt find the destination
}

void bfs(string src, string des)
{
    bool visit[vertices];
    for (int i = 0; i < vertices; i++)
        visit[i] = false;
    queue<int> q;

    q.push(src);
    visit[s] = true;
    while (!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (int i = 0; i < vertices; i++)
        {
            if ((mat[s][i] == 1) && (!visit[i]))
            {
                q.push(i);
                visit[i] = true;
            }
        }
    }
}

void resetCost()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cost[i][j] = -1;
}

int main()
{
    string source, destination;
    int first = 1;
    string src, dst;
    freopen("input.txt", "r", stdin);

    while (cin >> source >> destination)
    {
        resetCost();

        int res = bfs(source, destination);

        cout << "To get from " << source << " to " << destination << " takes " << res << " knight moves.\n";
    }
    return 0;
}
