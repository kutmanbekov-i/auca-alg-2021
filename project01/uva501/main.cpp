#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    int k; cin >> k;
    
    for (int j = 0; j < k; ++j)
    {
        int m, n;
        cin >> m >> n;
        
        multiset <int> A;
        vector <int> u(n), temp(m);
        
        for (int i = 0; i < m; ++i)
            cin >> temp[i];
        
        
        for (int i = 0; i < n; ++i)
            cin >> u[i];
        
        
        A.insert(temp[0]);
        auto cur = A.begin();
        
        int get_index = 0;
        
        for (int i = 1; i < m; ++i)
        {
            // ++added;
            while (get_index < n and u[get_index] == i)
            {
                ++get_index;
                cout << *cur << '\n';
                ++cur;
            }
            
            A.insert(temp[i]);
            if (cur == A.end() || temp[i] < *cur)
            {
                --cur;
            }
        }
        while (get_index < n and u[get_index] == m)
        {
            ++get_index;
            cout << *cur << '\n';
            ++cur;
        }
    }
}