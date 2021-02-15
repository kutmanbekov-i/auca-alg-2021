#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, t; cin >> t;
    
    while (t--)
    {
        cin >> n >> m;
        map<int, int> a;
        
        for (int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            a[x]++;
        }
        for (int i = 0; i < m; ++i)
        {
            int x; cin >> x;
            a[x]--;
        }
        
        int cnt = 0;
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            cnt += abs((*it).second);
        }
        cout << cnt << '\n';
    }
}