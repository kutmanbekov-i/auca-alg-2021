#include <bits/stdc++.h>

using namespace std;

static vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
static vector<int> dy = {0, 1, 0, -1, -1, 1, 1, -1};

static vector<vector<int>> perms = {{1, 0, 0, 0},
                                    {-1, 0, 0, 0},
                                    {0, 1, 0, 0},
                                    {0, -1, 0, 0},
                                    {0, 0, 1, 0},
                                    {0, 0, -1, 0},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, -1}};


int bfs(string &start, string &end, map <string, int> &Index)
{
    if (start == end)
        return 0;
    if (Index[end] == -1)
        return -1;

    queue<string> q;
    queue<int> q_index;

    q.push(start);
    q_index.push(1);

    while (!q.empty())
    {
        string u = q.front();
        q.pop();
        int idxu = q_index.front();
        q_index.pop();
        for (int k = 0; k < 7; ++k)
        {
            string v = u;
            for (int i = 0; i < 4; i++)
            {
                v[i] += perms[k][i];
                if (v[i] < '0')
                    v[i] = '9';
                else if (v[i] > '9')
                    v[i] = '0';
            }
            int idx = Index[v];
            if (idx != 0)
                continue;
            if (v == end)
                return idxu;
            idx = Index[v] = idxu + 1;
            q.push(v);
            q_index.push(idx);
        }
    }
    return -1;
}

int main()
{
    int t, val, m;
    cin >> t;

    string start, end;
    while (t--)
    {
        map<string, int> Index;
        start = end = "";

        for (int i = 1; i < 4; ++i)
        {
            cin >> val;
            start += val + 48;
        }
        for (int i = 1; i < 4; ++i)
        {
            cin >> val;
            end += val + 48;
        }

        cin >> m;
        while (m--)
        {
            string tmp = "";
            for (int i = 1; i < 4; ++i)
            {
                cin >> val;
                tmp += val + 48;
            }
            Index[tmp] = -1;
        }
        Index[start] = 1;
        cout << bfs(start, end, Index) << '\n';
    }
}