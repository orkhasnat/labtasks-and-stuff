#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int mat[100][100];

void warshall(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (mat[i][j] > mat[i][k] + mat[k][j] && mat[i][k] != INF && mat[k][j] != INF)
                    mat[i][j] = mat[i][k] + mat[k][j];
        }
    }
}

int main()
{
    int t, T, M, N, E;
    cin >> t;
    while (t--)
    {
        memset(mat, INF, sizeof(mat));
        cin >> N >> E >> T >> M;
        int a, b, w;
        for (int i = 0; i < M; i++)
        {
            cin >> a >> b >> w;
            mat[a][b] = w;
        }
        warshall(N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
}

// 1
// 4
// 2
// 1
// 8
// 1 2 1
// 1 3 1
// 2 1 1
// 2 4 1
// 3 1 1
// 3 4 1
// 4 2 1
// 4 3 1