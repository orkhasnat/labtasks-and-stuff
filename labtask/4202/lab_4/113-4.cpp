#include <iostream>
#include <vector>
int r, c, nc;
std::vector<std::vector<int>> img;
void floodfill(int x, int y, int ic, int nc,std::vector<std::vector<bool>> &vis)
{
    if (x < 0 || y < 0 || x >= r || y >= c)
        return;
    if (vis[x][y] || img[x][y] != ic)
        return;
    img[x][y]= nc;
    vis[x][y] = true;
    floodfill(x - 1, y, ic, nc,vis);
    floodfill(x, y - 1, ic, nc,vis);
    floodfill(x + 1, y, ic, nc,vis);
    floodfill(x, y + 1, ic, nc,vis);
}

int main()
{
    int sr, sc;
    std::cin >> r >> c >> sr >> sc >> nc;
    for (int i = 0; i < r; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < c; j++)
        {
            int tmp;
            std::cin >> tmp;
            row.push_back(tmp);
        }
        img.push_back(row);
        row.clear();
    }
    std::vector<std::vector<bool>> vis(r, std::vector<bool>(c, false));
    floodfill(sr, sc, img[sr][sc], nc,vis);
    std::cout << std::endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            std::cout << img[i][j] << " ";
        std::cout << "\n";
    }
}
