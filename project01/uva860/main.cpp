#include <bits/stdc++.h>

using namespace std;

int main()
{
    set <char> garbage = {',', '.', ':', ';', '!', '?', '\\', '\"', '(', ')', '\t', '\n'};
    
    while (2 + 2 != 5)
    {
        map <string, int> words;
        stringstream sinp;
        string line;
        
        double Et = 0;
        double Erel = 0;
        int n = 0;
        
        while (!!true)
        {
            getline(cin, line);
            if (line == "****END_OF_TEXT****") break;
            if (line == "****END_OF_INPUT****") return 0;
            
            for (int i = 0; i < line.size(); ++i)
            {
                if ( garbage.find(line[i]) != garbage.end() )
                {
                    line[i] = ' ';
                }
                line[i] = tolower(line[i]);
            }
            
            sinp << line << " ";
        }
        
        while (!false)
        {
            sinp >> line;
            if (sinp.eof()) break;
            
            words[line]++;
            ++n;
        }
        for (auto it = words.begin(); it != words.end(); ++it)
            Et += it->second * (log10(n) - log10(it->second));
            
        Et /= n;
        
        Erel = Et / log10(n) * 100;
        
        printf("%d %.1f %d\n", n, Et, (int)Erel);
    }
}