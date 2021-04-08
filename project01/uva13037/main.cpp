#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    int t; cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int l, r, s;
        cin >> l >> r >> s;
        
        set<int> L, R, S, common;
        
        for (int i = 0; i < l; ++i)
        {
            int x; cin >> x;
            L.insert(x); common.insert(x);
        }
        for (int i = 0; i < r; ++i)
        {
            int x; cin >> x;
            R.insert(x); common.insert(x);
        }
        for (int i = 0; i < s; ++i)
        {
            int x; cin >> x;
            S.insert(x); common.insert(x);
        }
        
        int l_have = 0; int l_do_not_have = 0;
        int r_have = 0; int r_do_not_have = 0;
        int s_have = 0; int s_do_not_have = 0;
        
        for (auto x : common)
        {
            if (L.count(x) and !R.count(x) and !S.count(x))
                ++l_have;
            else if (!L.count(x) and R.count(x) and S.count(x))
                ++l_do_not_have;
            if (!L.count(x) and R.count(x) and !S.count(x))
                ++r_have;
            else if (L.count(x) and !R.count(x) and S.count(x))
                ++r_do_not_have;
            if (!L.count(x) and !R.count(x) and S.count(x))
                ++s_have;
            else if (L.count(x) and R.count(x) and !S.count(x))
                ++s_do_not_have;
        }
        
        cout << "Case #" << j << ":\n";
        cout << l_have << " " << l_do_not_have << '\n';
        cout << r_have << " " << r_do_not_have << '\n';
        cout << s_have << " " << s_do_not_have << '\n';
    }
}