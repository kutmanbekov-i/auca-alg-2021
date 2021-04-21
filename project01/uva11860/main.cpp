#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string line, temp;
    int t; cin >> t;
    
    getline(cin, line);
    for (int k = 1; k <= t; ++k)
    {
        vector<string> words;
        
        while (getline(cin, line) and line != "END")
        {
            temp.clear();

            for (size_t i = 0; i < line.size(); ++i)
            {
                if (isalpha(line[i]))
                {
                    temp += line[i];
                }
                if (!temp.empty() and (!isalpha(line[i]) or i + 1 == line.size()))
                {
                    words.push_back(temp);
                    temp.clear();
                }
            }
        }

        unordered_set <string> unique_words(words.begin(), words.end());
        unordered_map <string, bool> seen;

        int first = 0, second = 0;
        
        size_t len = unique_words.size();
        
        for (size_t i = 0; i < words.size(); ++i)
        {
            seen.clear();
            int unix = 0;
        
            for (size_t j = i; j < i + len; ++j)
            {
                if (!seen[words[j]])
                {
                    seen[words[j]] = true;
                    ++unix;
                }
            }
 
            if (unix == len)
            {
                first = i + 1;
                second = i + len;
                break;
            }
        }
        cout << "Document " << k << ": " << first << " " << second << '\n';
    }
}