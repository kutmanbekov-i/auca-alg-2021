#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    string category, word, line, txt;
    
    while (n--)
    {
        int c; cin >> c;
        
        vector<string> order;
        multimap <string, string> words;
        map <string, int> fit_req, appears;
        
        while (c--)
        {
            int w, p;
            cin >> category >> w >> p;
            
            map <string, bool> checked;
            fit_req[category] = p;
            order.emplace_back(category);
            
            for (int i = 0; i < w; ++i)
            {
                cin >> word;
                if (checked.find(word) == checked.end())
                {
                    words.insert( { word, category } );
                    checked[word] = true;
                    // appears[word] = 0;
                }
            }
        }
        map <string, bool> checked;
        getline(cin, line);

        while (getline(cin, line) and line != "")
        {
            for (int i = 0; i < line.size(); ++i)
            {
                if (!isalpha(line[i]))
                {
                  line[i] = ' ';
                }
            }

            istringstream sinp(line);
            
            while (sinp >> line)
            {
                if (checked.find(line) != checked.end())
                {
                    continue;
                }
                checked[line] = true;
                
                if (words.count(line) > 0)
                {
                    auto res = words.equal_range(line);     // multimap keeps its elements sorted by key values
                    
                    for (auto it = res.first; it != res.second; ++it)
                    {
                        ++appears[it->second];
                    }
                }
            }
        }

        int first = 0;
        for (const string &w : order)
        {
            if (appears[ w ] >= fit_req[ w ])
            {
                if (first)
                        cout << ",";
                cout << w;
                ++first;
            }
        }
        if (!first)
                cout << "SQF Problem.";
        cout << '\n';
    }
}