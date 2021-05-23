#include <bits/stdc++.h>

using namespace std;

vector <int> dx = {-1, 0, 1, 0};
vector <int> dy = {0, 1, 0, -1};

struct Edge
{
    int r, c;
    int cost;
    // For std::priority_queue.
    bool operator>(const Edge &e) const
    {
        return this->cost > e.cost;
    }
};

int main()
{    
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int> > maze(n, vector<int>(m));

        for (int r = 0; r < n; ++r)
            for (int c = 0; c < m; ++c)
                cin >> maze[r][c];

        priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
        vector<vector<int> > cost(n, vector<int>(m, -1));

        // Dijkstra's algorithm using min-heap.
        Edge e;
        e.r = 0;
        e.c = 0;
        e.cost = maze[0][0];
        pq.push(e);
        cost[0][0] = e.cost;
        while (!pq.empty())
        {
            Edge u = pq.top();
            pq.pop(); 
            for (int i = 0; i < 4; ++i)
            {
                int r = u.r + dx[i];
                int c = u.c + dy[i];
                if (r < 0 or r >= n || c < 0 or c >= m)
                    continue;
                if (cost[r][c] == -1 or cost[u.r][u.c] + maze[r][c] < cost[r][c])
                {
                    cost[r][c] = cost[u.r][u.c] + maze[r][c];
                    e.r = r;
                    e.c = c;
                    // Store cost[r][c] rather than maze[r][c].
                    e.cost = cost[r][c];
                    pq.push(e);
                }
            }
        }
        cout << cost[n - 1][m - 1] << endl;
    }
    return 0;
}