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
        
        multiset<int, greater<int>> green;
        multiset<int, greater<int>> blue;
        
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
        
        for (auto p = green.begin(), q = blue.begin(); p != green.end() and q != blue.end(); )
        {
            int x = min(*p, *q);
            
            if (*p - x)
                green.insert(*p - x);
            if (*q - x)
                blue.insert(*q - x);
                
            p = green.erase(p);
            q = blue.erase(q);
    
                
            // ++p; ++q;            no need to increment, because erase returns pointer to the next element
            p = green.begin();
            q = blue.begin();
        }
        // cout << *green.begin() << ' ' << *blue.begin() << endl;

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