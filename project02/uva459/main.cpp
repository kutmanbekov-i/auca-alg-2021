#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>> &G,  vector<int> &dfsNum, int u)
{
    dfsNum[u] = 1;
    
    for (int j = 0; j < (int)G[u].size(); ++j)
    {
        int v = G[u][j];
        
        if (dfsNum[v] == 0)
            dfs(G, dfsNum, v);
    }
}

int main()
{  
    int t; cin >> t;
    while (t--)
    {
        char c; cin >> c;
        
        int nNodes = c - 'A' + 1;
        
        cin.ignore();

        vector<vector<int>> G(nNodes);
        vector<int> dfsNum(nNodes, 0);
        string s;
        while (getline(cin, s) and s != "")
        {
            // G is an undirected graph.
            G[s[0] - 'A'].push_back(s[1] - 'A');
            G[s[1] - 'A'].push_back(s[0] - 'A');
        }

        int cnt = 0;
        for (int i = 0; i < nNodes; ++i)
        {
            if (dfsNum[i] == 0)
            {
                ++cnt;
                dfs(G, dfsNum, i);
            }
        }
        cout << cnt << '\n';
        if (t)
            cout << '\n';
    }
    return 0;
}