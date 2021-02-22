#include <bits/stdc++.h>

using namespace std;

int main()
{
    set <string> dict;
    
    for (string word; cin >> word; )
    {
        string temp = "";
        for (char c : word)
        {
            if (isalpha(c))
            {
                temp += tolower(c);
            }
            else if (temp != "")
            {
                dict.insert(temp);
                temp = "";
            }
        }
        if (temp != "")
        {
            dict.insert(temp);
        }
    }
    
    for (const string &s: dict)
    {
        cout << s << '\n';
    }
}