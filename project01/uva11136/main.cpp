#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    
    while (cin >> n, n)
    {
        multiset<int> bills;
        
        size_t paid = 0;
        
        while (n--)
        {
            int k; cin >> k;

            while (k--)
            {
                int x; cin >> x;
                
                bills.insert(x);
            }
            
            auto min_p = bills.begin(), max_p = --bills.end();
            
            paid += *max_p - *min_p;
            
            bills.erase(max_p); bills.erase(min_p);
            
        }
        cout << paid << '\n';
    }
}