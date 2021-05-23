#include <bits/stdc++.h>

using namespace std;

static vector <int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
static vector <int> dy = {0, 1, 0, -1, -1, 1, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    
    int t; cin >> t;
    string word, line;
    
    while (t--)
    {
        vector<string> words;
        
        
        while (cin >> word and word != "*")
        {
            words.emplace_back(word);
        }
        
        string start, end;
        cin.ignore();
        
        while (getline(cin, line) and line != "")
        {
            istringstream sinp(line);

            sinp >> start >> end;
            // BFS
            queue<string> q;
            map<string, int> transform;

            transform[start] = 0;
            q.push(start);
            
            while (!q.empty() and transform.count(end) == 0)
            {
                string u = q.front();
                q.pop();
                // Loop over every word in the dictionary.
                for (size_t i = 0; i < words.size(); ++i)
                {
                    const string &v = words[i];
                    if (! transform.count(v) && u.length() == v.length())
                    {
                        int diff = 0;
                        for (size_t j = 0; j < u.length(); ++j)
                            if (u[j] != v[j])
                                ++diff;
                        if (diff == 1)
                        {
                            transform[v] = transform[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }    
            cout << start << " " << end << " " << transform[end] << '\n';

        }
        if (t)
                cout << '\n';
    }
    
    return 0;
}