#include <iostream>
#include <list>

using namespace std;

void print(const list<int> &v)
{
    for (auto e : v)
    {
        cout << e << ' ';
    }
    cout << '\n';
}

void printReversed(const list<int> &v)
{
    for (auto p = v.rbegin(); p != v.rend(); ++p)
    {
        cout << *p << ' ';
    }
    cout << '\n';
}

int main()
{
    list<int> v;

    for (int x; cin >> x; )
    {
        v.push_back(x);
    }

    print(v);
    printReversed(v);

    for (auto p = v.begin(); p != v.end(); ++p)
    {
        if (*p % 2 == 0)
        {
            v.insert(p, 0);  
        }
    }

    print(v);
    printReversed(v);

    for (auto p = v.begin(); p != v.end(); )
    {
        if (*p % 2 == 0)
        {
            p = v.erase(p);
        }
        else
        {
            ++p;
        }
        
    }

    print(v);
    printReversed(v);
}
