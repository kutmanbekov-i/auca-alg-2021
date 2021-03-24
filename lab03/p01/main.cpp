#include <iostream>
#include <map>

using namespace std;

int main()
{

    map<string, int> v;

    for (string s; cin >> s;)
    {
        auto it = v.find(s);

        v.insert({s, v[s]++});
    }

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        string s = it->first;
        cout << s << ": " << v[s] << '\n';
    }
}