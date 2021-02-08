#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    vector<string> a;
    vector<string> b;
    unordered_set<string> concat;
    
    int m, n, cases = 1, t; cin >> t;
    while (t--)
    {
        a.clear();
        b.clear();
        concat.clear();
        
        cin >> m >> n;
        
        string t; getline(cin, t);
        
        for (int i = 0; i < m; ++i)
        {
            string s;
            getline(cin, s);
            a.push_back(s);
        }
        for (int i = 0; i < n; ++i)
        {
            string s; getline(cin, s);
            b.push_back(s);
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                concat.insert(a[i] + b[j]);
            }
        }
        cout << "Case " << cases++ << ": " << concat.size() << '\n';
    }
}