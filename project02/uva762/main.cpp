#include <bits/stdc++.h>

using namespace std;

static vector <int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
static vector <int> dy = {0, 1, 0, -1, -1, 1, 1, -1};

int bfs(string src, string dest, map <string, vector<string>> grid, map <string, int> &used, map <string, string> &route)
{
    queue <string> q;
    q.push(src);
    used[src] = 1;
        
    while (q.empty() == false)
    {
        string top = q.front();
        q.pop();

        
        if (top == dest)
        {
            return used[top];
        }
        
        for(size_t i = 0; i < grid[top].size(); i++)
        {
            string s = grid[top][i]; 
            
            if(used[s] == -1)
            {         
                used[s] = used[top] + 1;            // Number of moves until here + 1, not necesary in this problem
                route[s] = top;                     // Addtion: The parent of n is top.
                q.push(s);
            }
        }
    }

    return -1;
}

void printpath(string a, string b, map <string, string> &route)
{
    if (a == b) return;
  
    printpath (route[a], b, route);
  
    cout << route[a] << " " << a << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    
    int n;
    bool line = false;
    string src, dest, s1, s2;
    
    while(cin >> n)
    {
        map <string, vector<string>> grid;
        map <string, string> route;
        map <string, int> used;
        
        for (int i = 0; i < n; ++i)
        {
            cin >> s1 >> s2;
            
            grid[s1].push_back(s2);
            grid[s2].push_back(s1);
            
            used[s1] = -1;
            used[s2] = -1;
        }

        cin >> src >> dest;
        
        if (line) cout << '\n';
        line = true;
        
        if (bfs(src, dest, grid, used, route)  != -1)
        {
            printpath(dest, src, route);
        }
        else
            cout << "No route\n";

    }
    
    return 0;
}