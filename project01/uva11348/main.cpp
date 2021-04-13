#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n; cin >> n;
        multimap<int, int> types;       // <type, whom belongs to>
        vector<int> uniques(n);

        map<int, int> elements;         // type, count
        for (int j = 0; j < n; ++j)
        {
            int m; cin >> m;
            for (int k = 0; k < m; ++k)
            {
                int a; cin >> a;
                
                auto it = types.find(a);
                
                if (it == types.end() or (it != types.end() and it->second != j))
                    types.insert({a, j});
            }
        }
        
        int unix = 0, ind = 0;
        for (auto it = types.begin(); it != types.end(); ++it)
        {
            ++elements[it->first];
        }
        for (auto it = elements.begin(); it != elements.end(); ++it, ++ind)
        {
            if (it->second == 1)
            {
                auto p = types.find(it->first);
                // cout << p->first << ": " << p->second << '\n';
                ++uniques[p->second];
                ++unix;
            }
        }
        auto it = types.begin();
        cout << "Case " << i + 1 << ":";
        
        for (int j = 0; j < n; ++j, ++it)
        {
            printf (" %.6f%%", (double)uniques[j] / unix * 100);
        }
        
        cout << '\n';
    }
}