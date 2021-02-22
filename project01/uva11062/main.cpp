#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> dict;
    string temp;

    for (string s; cin >> s;)
    {
        size_t len = s.length();
        
        for (int i = 0; i < len; ++i)
        {
            char c = s[i];
            
            if (isalpha(c))
            {
                temp += tolower(c);
                
                if (i == len - 1)                   // if the last char is letter, then word is completed
                {
                    dict.insert(temp);
                    temp = "";
                }
            }
            else if (c == '-' and i != len - 1)     // hyphen is in the middle
            {
                temp += c;
            }
            else if (c != '-' and !temp.empty())    // non alpha
            {
                dict.insert(temp);
                temp = "";
            }
            
        }
    }
    for (const string &s : dict)
    {
        cout << s << '\n';
    }
}