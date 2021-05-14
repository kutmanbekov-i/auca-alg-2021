#include <bits/stdc++.h>

#include "algol.h"

using namespace std;

void print_vector(const vector<int> &v)
{
    for (int e : v)
    {
        cout << " " << e;
    }
    cout << '\n';
}

int main()
{
    vector<int> v = {-42, 3301, 31415, 271828, 161803, 1, 2, 3, 4, 5};
    size_t n = v.size();

    cout << "Before sorting:";
    print_vector(v);

    quick_sort(v, 0, n - 1);

    cout << "After sorting:";
    print_vector(v);
}