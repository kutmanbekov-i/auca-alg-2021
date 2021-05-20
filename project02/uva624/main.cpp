#include <iostream>
#include <vector>

using namespace std;

void solve(size_t c, int sum, int d, vector<int> &v, vector<bool> &best, vector<bool> &cur, int &bst)
{
    if (sum <= d and d - sum < d - bst)
    {
        bst = sum;
        for (size_t i = 0; i < cur.size(); ++i)
        {
            best[i] = cur[i];
        }
    }
    if (sum > d or c >= (int)v.size() )
    {
        return;
    }

    cur[c] = true;
    solve(c + 1, sum + v[c], d, v, best, cur, bst);
    cur[c] = false;
    solve(c + 1, sum, d, v, best, cur, bst);

}

int main()
{
    for (int d, n; cin >> d >> n;)
    {
        vector<int> v(n);
        vector<bool> best(n), current(n);
        for (auto &e : v)
        {
            cin >> e;
        }
        
        int bst = 0;

        solve(0, 0, d, v, best, current, bst);
        for (size_t i = 0; i < v.size(); i++)
        {
            if (best[i])
            {
                cout << v[i] << ' ';
            }
        }
        cout << "sum:" << bst << '\n';
        
    }
}