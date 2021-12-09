#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int mat[1001][1001];
int vis[1001][1001];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
#define FILE "input_4_66224.txt"
int main()
{

    int h, w;
    memset(mat, 0, sizeof(mat));
    memset(vis, 0, sizeof(vis));
    freopen(FILE,"r",stdin);
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '!')
                mat[i][j] = 0;
            else
                mat[i][j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == 0 || vis[i][j])
                continue;
            ans++;
            stack<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty())
            {
                pair<int, int> cur = /*q.front();*/q.top();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int x = cur.first + dx[k];
                    int y = cur.second + dy[k];
                    if (x < 0 || x >= h || y < 0 || y >= w)
                        continue;
                    if (mat[x][y] == 0 || vis[x][y])
                        continue;
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }
    cout << ans << "\n";
}
