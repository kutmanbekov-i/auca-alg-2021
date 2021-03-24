#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main()
{
    int n = 0;
    map<string, set<int>> m;

    for (string line; getline(cin, line);)
    {
        ++n;
        istringstream sin(line);

        for (string word; sin >> word;)
        {
            m[word].insert(n);
        }
    }

    for (const auto &it : m)
    {
        cout << it.first << ": ";
        for (const auto &p : it.second)
        {
            cout << " " << p;
        }
        cout << '\n';
    }
}