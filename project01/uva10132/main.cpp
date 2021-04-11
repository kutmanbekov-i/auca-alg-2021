#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}

int main()
{
    string line, temp_t;

    getline(cin, temp_t);
    int t = stoi(temp_t);

    getline(cin, line); // blank line after the input

    for (int j = 0; j < t; ++j)
    {
        if (j)
            cout << '\n';

        map<string, string> fragments;
        vector<string> v;

        while (getline(cin, line) and line != "")
        {
            v.emplace_back(line);
        }
        sort(v.begin(), v.end(), cmp);

        for (int i = 0, k = v.size() - 1; k >= i; ++i, --k)
        {
            fragments.insert({v[i], v[k]});
        }

        string out;

        auto it2 = fragments.begin();

        if (fragments.size() == 1)
        {
            out = it2->first + it2->second;
        }
        else
        {
            ++it2;
            // cout << fragments.size();

            for (auto it = fragments.begin(); it2 != fragments.end(); ++it, ++it2)
            {
                if (it->first + it->second == it2->first + it2->second or
                    it->second + it->first == it2->first + it2->second or
                    it->first + it->second == it2->second + it2->first or
                    it->second + it->first == it2->second + it->first)
                {
                    out = it->first + it->second;
                    break;
                }
            }
        }
        cout << out << '\n';
    }
}