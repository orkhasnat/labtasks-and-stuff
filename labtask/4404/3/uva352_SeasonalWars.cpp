#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int N = 30;

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int g[N][N];
bool vis[N][N];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int tc = 0;
    while (cin >> n)
    {
        memset(g, 0, sizeof g);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char ch;
                cin >> ch;
                g[i][j] = ch - '0';
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (g[i][j] == 0 or vis[i][j])
                    continue;
                ++ans;
                queue<ii> q;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty())
                {
                    ii cur = q.front();
                    q.pop();
                    for (int k = 0; k < 8; ++k)
                    {
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];
                        if (x < 0 or x >= n or y < 0 or y >= n)
                            continue;
                        if (g[x][y] == 0 or vis[x][y])
                            continue;
                        vis[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }
        cout << "Image number " << ++tc << " contains " << ans << " war eagles."
             << "\n";
    }
    return 0;
}