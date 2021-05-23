#include <bits/stdc++.h>

using namespace std;

static vector <int> dx = {0, 0, 1, -1, 1, -1};
static vector <int> dy = {1, -1, 0, 0, 1, -1};

void dfs (const vector<string> &grid, vector<vector<int>> &seen, int p, int q, bool &black_wins)
{
    int n = (int)grid.size();
    
    if (p == n - 1)
    {
        black_wins = true;
        return;
    }
    
    seen[p][q] = 1;

    for(int i = 0; i < (int)dx.size(); i++)
    {
        int x = p + dx[i];
        int y = q + dy[i];
        
        if (x >= 0 and y >= 0 and x < n and y < n and grid[x][y] == 'b' and !seen[x][y])
            dfs(grid, seen, x, y, black_wins);
    }
}

int main()
{
    
    int t = 0;
    int n;
    
    while(cin >> n and n)
    {
        vector<vector<int>> seen(n, vector<int> (n, 0));
        vector <string> grid(n);
        
        for(int i = 0; i < n; i++)
        {
            cin >> grid[i];            
        }

        bool black_wins = false;
        
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 'b' and !seen[0][i] and !black_wins)
                dfs(grid, seen, 0, i, black_wins);
        }
        
        cout << ++t << " ";
        
        if (!black_wins)    cout << "W\n";
        else                cout << "B\n";
    }
    
    return 0;
}