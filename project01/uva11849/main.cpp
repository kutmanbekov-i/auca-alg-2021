#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    while (cin >> n >> m)
    {
        if (n == 0 and m == 0) break;
        
        int cnt = 0;
        vector<bool> v(1000000001, false);      // or set<int> v;
        
        for (int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            v[x] = true;                        // v.insert(x);
        }
        for (int i = 0; i < m; ++i)
        {
            int x; cin >> x;
            if (v[x])                           // if (v.find(x) != v.end())
            {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
}