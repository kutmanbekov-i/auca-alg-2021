#include <iostream>
#include <cstdint>

using namespace std;

int64_t fact(int x)
{
    if (x <= 1)
    {
        return 1;
    }
    return x * fact(x - 1);
}

int main()
{
    for (int x; cin >> x;)
    {
        cout << "Factorial of " << x << " = " << fact(x) << '\n';
    }
}