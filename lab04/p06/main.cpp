#include <iostream>

using namespace std;

int64_t fib(int64_t n)
{
    if (n <= 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int64_t fib_iter(int n)
{
    if (n <= 1) return 1;
    int64_t f0 = 1;
    int64_t f1 = 1;

    for (int i = 2; i < n; ++i)
    {
        int64_t temp = f0 + f1;
        f0 = f1;
        f1 = temp;
    }
    return f1;
}

int main()
{
    for (int n; cin >> n;)
    {
        cout << "fib(n) = " << fib_iter(n) << '\n';
    }
}