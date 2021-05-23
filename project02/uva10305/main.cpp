#include <bits/stdc++.h>

using namespace std;

static vector <int> dx = {1, 0, -1, 0};
static vector <int> dy = {0, 1, 0, -1};

void print(vector<vector<int>> &graph, int n, vector<int> &seen, int u, int &space)
{
// 	cnt++;
	
	seen[u] = 1;
	
	for(int v = 1; v <= n; v++)
	{
		if(!seen[v] and graph[u][v])			
			print(graph, n, seen, v, space);
	}
	
	if (space++)
	    cout << " ";
	cout << u;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    
    while(cin >> n >> m)
    {
        if (!n and !m) break;
        
        vector<vector<int>> graph(101, vector<int> (101, 0));
        vector <int> seen(101);
        
        while (m--)
        {
            int i, j; cin >> i >> j;
            
            graph[j][i] = 1;
        }
        
        int space = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (!seen[i])
            {
                print(graph, n, seen, i, space);
            }
        }
        cout << '\n';
    }
    
    return 0;
}