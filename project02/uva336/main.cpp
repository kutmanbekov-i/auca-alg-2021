#include <bits/stdc++.h>

using namespace std;

static vector <int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
static vector <int> dy = {0, 1, 0, -1, -1, 1, 1, -1};

int main()
{
    int n, t = 1;
    while (cin >> n and n)
    {
        map<int, vector<int>> grid;

        for (int i = 0; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            grid[u].push_back(v);
            grid[v].push_back(u);
        }
        int s, ttl;
        
        while (cin >> s >> ttl)
        {
            if (!s and !ttl) break;
            // Use BFS to solve the SSSP problem.
            queue<int> q;
            map<int, int> dist;
            // The starting node is always reachable.
            int reachable_nodes = 1;

            dist[s] = 0;
            q.push(s);
            
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (size_t i = 0; i < grid[u].size(); ++i)
                {
                    int v = grid[u][i];
                    
                    if (!dist.count(v))
                    {
                        dist[v] = dist[u] + 1;
                        if (dist[v] <= ttl)
                        {
                            q.push(v);
                            ++reachable_nodes;
                        }
                    }
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", t++, (int)grid.size() - reachable_nodes, s, ttl);
        }
        
    }
    
    return 0;
}