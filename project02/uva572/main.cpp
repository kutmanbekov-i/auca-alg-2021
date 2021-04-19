#include <bits/stdc++.h>

using namespace std;

void dfs(int r, int c, vector<string> &grid)
{
    static vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1}; // created only once and visible only in dfs (but they are global)
    static vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

    //videl[x][y] = 1;
    grid[r][c] = '!';

    for (int k = 0; k < 8; k++)
    {
        int x = r + dx[k];
        int y = c + dy[k];
        if ( 0 <= x and x < int(grid.size()) and 0 <= y and y < (int)grid[0].size() and grid[x][y] == '@')
        {
            //videl[x][y] = 1;
            dfs(x, y, grid);
        }
    }
}

int main()
{
    for (int h, w; cin >> h >> w and h and w;)
    {
        vector<string> grid(h);

        for (int r = 0; r < h; ++r)
        {
            cin >> grid[r];
        }

        int nComps = 0;

        for (int r = 0; r < h; ++r)
        {
            for (int c = 0; c < w; ++c)
            {
                if (grid[r][c] == '@')
                {
                    ++nComps;
                    dfs(r, c, grid);
                }
            }
        }

        cout << nComps << '\n';
    }

    return 0;
}