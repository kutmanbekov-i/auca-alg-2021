#include <bits/stdc++.h>

#include "algol.h"

using namespace std;

int main()
{
    vector<int> v = {3301, 31415926, 271828, 161803, 1, 2, 3, 4, 5};
    sort(v.begin(), v.end());

    for (int e : v)
    {
        cout << e << " ";
    }
    cout << '\n';

    size_t n = v.size();

    for (int x; cin >> x;)
    {
        int result = binary_search(v, n, x);

        (result == -1) ? cout << "Element " << x << " is not present in array\n"
                       : cout << "Element " << x << " is in array at index " << result << '\n';
    }
}