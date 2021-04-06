#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    int n; cin >> n;
    
    int b, sg, sb;
    
    for (int j = 0; j < n; ++j)
    {
        if (j) cout << '\n';
        cin >> b >> sg >> sb;
        
        multiset<int, greater<int>> green, blue;
        
        vector <int> G, B;
        
        for (int i = 0; i < sg; ++i)
        {
            int x; cin >> x;
            green.insert(x);
        }
        for (int i = 0; i < sb; ++i)
        {
            int x; cin >> x;
            blue.insert(x);
        }
        
        while (!green.empty() and !blue.empty())
        {
            G.clear(); B.clear();
            
            for (int i = 0; i < b; ++i)
            {
                auto p = green.begin();
                auto q = blue.begin();
                
                int x = min(*p, *q);
                
                if (*p - x)
                {
                    blue.erase(q);
                    green.erase(p);
                    G.push_back(*p - x);
                }
                else if (*q - x)
                {
                    green.erase(p);
                    blue.erase(q);
                    B.push_back(*q - x);
                }
                else
                {
                    p = green.erase(p);
                    q = blue.erase(q);
                }
                
                if (green.size() == 0 || blue.size() == 0) break;
            }
            
            for (int i = 0; i < G.size(); ++i)
                green.insert(G[i]);
            for (int i = 0; i < B.size(); ++i)
                blue.insert(B[i]);
        }

        if (*blue.begin() < *green.begin())
        {
            cout << "green wins\n";
            for (auto p = green.begin(); p != green.end(); ++p)
            {
                cout << *p << '\n';
            }
        }
        else if (*green.begin() < *blue.begin())
        {
            cout << "blue wins\n";
            for (auto p = blue.begin(); p != blue.end(); ++p)
            {
                cout << *p << '\n';
            }
        }
        else
        {
            cout << "green and blue died\n";
        }
    }
}