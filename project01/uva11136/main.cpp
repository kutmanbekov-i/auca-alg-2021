#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        
        multiset<int> bills;
        int paid = 0;
        auto min_p = bills.end(), max_p = bills.end();
        
        while (n--)
        {
            int k; cin >> k;

            for (int i = 0; i < k; ++i)
            {
                int x; cin >> x;
                bills.insert(x);
            }
            
            int min = 1000001, max = -1;
            for (auto it = bills.begin(); it != bills.end(); ++it)
            {
                if (*it < min)      { min = *it; min_p = it; }
                else if (*it > max) { max = *it; max_p = it; }
            }
            
            bills.erase(max_p);
            bills.erase(min_p);
            
            paid += max - min;
        }
        cout << paid << '\n';
    }
}