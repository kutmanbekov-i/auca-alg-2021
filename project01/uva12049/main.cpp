#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, t; cin >> t;
    
    while (t--)
    {
        cin >> n >> m;
        vector<int> a(10001, 0);
        
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
        for (int k = 0; k < 10001; ++k)
        {
            cnt += abs(a[k]);
        }
        cout << cnt << '\n';
    }
}