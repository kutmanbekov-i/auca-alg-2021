#include <bits/stdc++.h>

using namespace std;

static vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
static vector<int> dy = {0, 1, 0, -1, -1, 1, 1, -1};

int main()
{
    int e, t, n;
    cin >> e;

    vector<int> link[e];
    for (int i = 0; i < e; i++)
    {
        link[i].clear();
        cin >> n;

        while (n--)
        {
            int x; cin >> x;
            link[i].push_back(x);
        }
    }
    cin >> t;
    while (t--)
    {
        int x; cin >> x;
        vector<int> dp(e), used(e), cnt(e + 1);

        used[x] = 1;
        queue<int> q;
        q.push(x);
        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto it = link[top].begin(); it != link[top].end(); it++)
            {
                if (!used[*it])
                {
                    used[*it] = 1;

                    q.push(*it);
                    dp[*it] = dp[top] + 1;

                    cnt[dp[*it]]++;
                }
            }
        }
        int m = 0, d;
        for (int i = 1; i <= e; i++)
        {
            if (cnt[i] > m)
            {
                m = cnt[i];
                d = i;
            }
        }
        if (m)
            cout << m << " " << d << '\n';
        else
            cout << '0' << '\n';
    }

    return 0;
}