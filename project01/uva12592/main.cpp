#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n; cin >> n;
    string line, first, second;
    
    getline(cin, line);
    unordered_map<string, string> slogans;
    
    for (int i = 0; i < 2 * n; ++i)
    {
        getline(cin, line);
        if (i % 2 == 0)
            first = line;
        else
        {
            second = line;
        
            slogans[first] = second;
        }
    }
    
    int q; cin >> q;
    getline(cin, line);

    while (q--)
    {
        getline(cin, line);
        cout << slogans[line] << '\n';
    }
}