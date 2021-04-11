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

        map<string, int> fragments;
        vector<string> v;

        while (getline(cin, line) and line != "")
        {
            v.emplace_back(line);
        }
        sort(v.begin(), v.end(), cmp);

        for (int i = 0, k = v.size() - 1; k >= i; ++i, --k)
        {
            fragments[v[i] + v[k]]++;
            fragments[v[k] + v[i]]++;
        }
        
        // for (auto it = fragments.begin(); it != fragments.end(); ++it)
        // {
        //     cout << it->first << ": " << it->second << '\n';
        // }
        
        string out;
        int most_frequent = 0;
        
        for (auto it = fragments.begin(); it != fragments.end(); ++it)
        {
            if (it->second > most_frequent)
            {
                most_frequent = it->second;
                out = it->first;
            }
        }

        cout << out << '\n';
    }
}