#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    map <int, int> m;
    vector <int> order;
    
    for (int x; cin >> x; )
    {
        m[x]++;
        
        if (m[x] == 1)
            order.push_back(x);
    }
    for (int number : order)
    {
        cout << number << " " << m[number] << '\n';
    }
}