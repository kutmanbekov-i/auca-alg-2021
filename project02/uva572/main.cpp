#include <bits/stdc++.h>

using namespace std;

static vector <int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
static vector <int> dy = {0, 1, 0, -1, -1, 1, 1, -1};

void dfs(vector<string> &grid, vector<vector<int>> &seen, int i, int j)
{
// 	cnt++;
	
	int n = (int)grid.size();
	int m = (int)grid[0].size();
	
	seen[i][j] = 1;

    for(int k = 0; k <(int)dx.size(); k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        
        if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == '@' and !seen[x][y])
            dfs(grid, seen, x, y);
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    
    while(cin >> n >> m and n and m)
    {
        int cnt = 0;
        
        vector<vector<int>> seen(n, vector<int>(m));
        vector<string> grid(n);
        
        for (int i = 0; i < n; ++i)
        {
            cin >> grid[i];
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!seen[i][j] and grid[i][j] == '@')
                {
                    ++cnt;
                    dfs(grid, seen, i, j);
                }
            }
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}