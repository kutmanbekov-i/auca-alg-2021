#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (string s; getline(cin, s); )
    {
        list<char> r;
        auto p = r.end();

        for (char c : s)
        {
            if (c == '[')
            {
                p = r.begin();
            }
            else if (c == ']')
            {
                p = r.end();
            }
            else
            {
                r.insert(p, c);
            }
        }

        cout << string(r.begin(), r.end()) << '\n';
    }
}