#include <bits/stdc++.h>

using namespace std;

const int moves = 3;
const vector<int> x_moves = {-1, 0, 1};
const vector<int> y_moves = {0, -1, 0};
const vector<string> moveNames = {"left", "forth", "right"};

vector<string> output(7);       // max size is 8x8
const string path = "IEHOVA#";

bool can_go(vector<string> &grid, int x, int y, int index)
{
    if (grid[y][x] == '#')
    {
        cout << output[0];
        for (int i = 1; i < index; ++i)
            cout << ' ' << output[i];
        cout << '\n';
        return true;
    }
    else if (index == path.size())
        return false;
    
    for (int move = 0; move < moves; ++move)
    {
        int newX = x + x_moves[move], newY = y + y_moves[move];
        if (newX >= 0 and newX < grid[0].size() and newY >= 0 and newY < grid.size()
            and grid[newY][newX] == path[index])
        {
            // Try moving there
            output[index] = moveNames[move];
            if (can_go(grid, newX, newY, index + 1))
                return true;
        }
            
    }
    
    return false;
}

int main()
{
    int t; cin >> t;
    
    while (t--)
    {
        int m, n; cin >> m >> n;
        
        vector<string> grid(m);
        
        int pos_x, pos_y;
        
        for (int i = 0; i < m; ++i)
        {
            cin >> grid[i];
            
            if (i == m - 1)
                for (int j = 0; j < n; ++j)
                    if (grid[i][j] == '@')
                        pos_y = i, pos_x = j;
        }
        
        can_go(grid, pos_x, pos_y, 0);
    }
}