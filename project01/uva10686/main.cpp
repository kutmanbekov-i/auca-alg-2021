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
        unordered_map <string, set<string>> words;
        unordered_map <string, int> fit_req;
        unordered_map <string, int> appears;
        unordered_map <string, bool> checked;
        
        while (c--)
        {
            int w, p;
            cin >> category >> w >> p;
            
            fit_req[category] = p;
            order.emplace_back(category);
            for (int i = 0; i < w; ++i)
            {
                cin >> word;
                words[category].insert(word);
            }
        }
        
        set <string> text;
        getline(cin, line);
        
        while (getline(cin, line) and line != "")
        {
            istringstream sinp(line);
            while (sinp >> txt)
            {
                string temp;
                for (int i = 0; i < txt.size(); ++i)
                {
                    if (isalpha(txt[i]))
                    {
                        temp += txt[i];
                    }
                    else
                    {
                        text.insert(temp);
                        temp.clear();
                    }
                }
                text.insert(temp);
                // cout << temp << " ";
            }
        }
        int fit = 0;
        // for (auto it = words.begin(); it != words.end(); ++it)
        for (const string &w : order)
        {
            auto it = words.find(w);
            if (it == words.end())
                break;
                
            if (text.size() == 0)
            {
                if (fit_req[it->first] == 0)
                {
                    if (fit)
                            cout << ",";
                            
                    cout << it->first;
                    checked[it->first] = true;
                    ++fit;
                }
            }
            else
            {
                for (const string &s : text)
                {
                    if (it->second.count(s))
                    {
                        ++appears[it->first]; 
                    }
                    // cout << it->second.size() << '\n';
                    if (!checked[it->first] and appears[it->first] >= fit_req[it->first])
                    {
                        if (fit)
                                cout << ",";
                        cout << it->first;
                        
                        checked[it->first] = true;
                        ++fit;
                    }
                }
            }
        }
        
        if (!fit)
                cout << "SQF Problem.";
        cout << '\n';
    }
}