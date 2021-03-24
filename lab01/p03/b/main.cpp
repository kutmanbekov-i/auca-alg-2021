#include <iostream>
#include "List.hpp"

using namespace std;

void print(const List<int> &v)
{
    for (auto e : v)
    {
        cout << e << ' ';
    }
    cout << '\n';
}

void printReversed(const List<int> &v)
{
    for (auto p = v.rbegin(); p != v.rend(); ++p)
    {
        cout << *p << ' ';
    }
    cout << '\n';
}

int main()
{
    List<int> v;

    for (int x; cin >> x; )
    {
        v.pushBack(x);
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
