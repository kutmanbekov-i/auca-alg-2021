#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int n; cin >> n and n; )
    {
        //
        unordered_map <string, int> m;
        
        for (int i = 0; i < n; ++i)
        {
            int x;
            string temp;
            vector<int> v;
            
            for (int j = 0; j < 5; ++j)
            {
                cin >> x; v.push_back(x);
            }
            
            sort(v.begin(), v.end());
            for (int e : v)
            {
                temp += to_string(e);
            }
            
            m[temp]++;
            
        }
        
        int max = 0, cnt = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
            if (it->second >= max)
                max = it->second;
        for (auto it = m.begin(); it != m.end(); ++it)
            if (it->second == max)
                ++cnt;

        cout << cnt * max << '\n';
    }
}