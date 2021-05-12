#include <iostream>
#include <string>

#include "MapStrInt.hpp"

using namespace std;

int main()
{
    MapStrInt m;

    string word;
    while (cin >> word)
    {
        ++m[word];
    }

    m.printInOrder(cout);
    cout << "size: " << m.size() << endl;

    m.clear();
    cout << "size: " << m.size() << endl;
}