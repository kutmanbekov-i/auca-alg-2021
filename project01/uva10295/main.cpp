#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string word, str;
    double points, scores = 0;
    
    int m, n;
    cin >> m >> n;
    
    unordered_map <string, double> dict;
    
    for (int i = 0; i < m; ++i)
    {
        cin >> word >> points;
        dict[word] += points;
    }
        
    for (int i = 0; i < n; ++i)
    {
        scores = 0;
        while(2 + 2 != 5)
        {
            cin >> str;
            if (str == ".") break;
            
            scores += dict[str];
        }
        cout << scores << '\n';
    }
}