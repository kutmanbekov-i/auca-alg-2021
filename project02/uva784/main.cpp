#include <bits/stdc++.h>

using namespace std;

static vector <int> dx = {1, 0, -1, 0};
static vector <int> dy = {0, 1, 0, -1};

void dfs (int n, vector<string> &grid, vector<vector<int>> &seen, int i, int j)
{
    // int n = (int)grid.size();
    
    seen[i][j] = 1;

    for(int k = 0; k < (int)dx.size(); k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        
        if (x >= 0 and y >= 0 and x < n and y < n and (grid[x][y] == ' ') and !seen[x][y])
        {
            dfs(n, grid, seen, x, y);
        
            grid[x][y] = '#';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    
    string line, separate; getline(cin, line);
    
    while(t--)
    {
        vector <string> grid;
        int max_col = 0, num_rows = 0, n;
        
        while (getline(cin, line))
        {
            if (line[0] == '_')
            {
                separate = line;
                break;
            }
            
            grid.emplace_back(line);
            ++num_rows;
            if ((int)line.size() > max_col)
                max_col = (int)line.size();
            
        }
        n = max(max_col, num_rows);
        
        vector<vector<int>> seen(n, vector<int> (n, 0));
        
        int row, col;
        
        for (int r = 0; r < (int)grid.size(); ++r)
        {
            for (int c = 0; c < (int)grid[r].size(); ++c)
            {
                if (grid[r][c] == '*')
                {
                    grid[r][c] = '#';
                    row = r; col = c;
                    
                    dfs(n, grid, seen, r, c);
                    break;
                }
            }
        }
        
        for (int r = 0; r < (int)grid.size(); ++r)
        {
            for (int c = 0; c < (int)grid[r].size(); ++c)
            {
                cout << grid[r][c];
            }
            cout << '\n';
        }
        
        cout << separate << '\n';   
    }
    
    return 0;
}