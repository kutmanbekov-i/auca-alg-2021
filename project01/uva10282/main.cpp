#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string word, translation, msg, line;
    
    unordered_map <string, string> dict;
    
    while (getline(cin, line) and line != "")
    {
        istringstream sinp(line);
        
        sinp >> word >> translation;
        dict[translation] = word;
    }

    while (cin >> msg)
    {
        if (dict.find(msg) != dict.end())
        {
            cout << dict[msg] << '\n';
        }
        else
        {
            cout << "eh\n";
        }
    }
}