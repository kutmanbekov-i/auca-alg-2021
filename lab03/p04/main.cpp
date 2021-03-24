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

    m.printInOrder();
    cout << "size: " << m.size() << endl;
}