#include <iostream>

using namespace std;

// solve for n:
//      solve for n - 1 (put n-1 disk from source to dest)
//      put the biggest disk from source to dest
//      selve for n - 1 (put n-1 disk from temp to dest)

void solve(int n, int source, int temp, int dest)
{
    if (n != 0) // n > 1
    {
        solve(n - 1, source, dest, temp);
        cout << source << " -> " << dest << endl;
        solve(n - 1, temp, source, dest);
    }
    // else if (n == 1)
    // {
    //     cout << source << " -> " << dest << endl;
    // }
}

int main()
{
    int n;
    cin >> n;

    solve(n, 1, 2, 3);
}