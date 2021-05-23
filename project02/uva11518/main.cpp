#include <bits/stdc++.h>

using namespace std;

static vector <int> dx = {1, 0, -1, 0};
static vector <int> dy = {0, 1, 0, -1};

void dfs(vector<vector<int>> &graph, vector<int> &seen, int u, int &cnt)
{
	cnt++;
	
	seen[u] = 1;
	
	for(int v = 0; v < (int)graph[u].size(); v++)
	{
		if(!seen[graph[u][v]])			
			dfs(graph, seen, graph[u][v], cnt);
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    
    while(t--)
    {
        int n, m, l, cnt = 0;
        cin >> n >> m >> l;
          
        vector<vector<int>> graph(n + 1);
        vector <int> seen(n + 1);
        
        while(m--)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        
        while (l--)
        {
            int z; cin >> z;
            
            if (!seen[z])
                dfs(graph, seen, z, cnt);
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}