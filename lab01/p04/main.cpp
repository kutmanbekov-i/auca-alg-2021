#include <bits/stdc++.h>

using namespace std;

template <typename Container>
void experiment_with(const string &msg, int n)
{
    mt19937 rnd_gen;
    uniform_int_distribution<int> num_dist(0, numeric_limits<int>::max());

    auto t1 = chrono::high_resolution_clock::now();

    Container a;
    for (int i = 0; i < n; ++i)
    {
        int x = num_dist(rnd_gen);
        auto p = begin(a);
        while (p != end(a) && *p < x)
        {
            ++p;
        }
        a.insert(p, x);
    }
    auto t2 = chrono::high_resolution_clock::now();

    cout << msg << ": " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << '\n';
}

int main()
{
    const int n = 10000;

    experiment_with<vector<int>>("vector", n);
    experiment_with<list<int>>("list", n);
}