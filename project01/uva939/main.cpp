#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n; cin >> n;
    string name, second;
    
    map <string, pair<string, string>> children;
    map <string, string> genes;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> second;
        if (second == "dominant" or second == "recessive" or second == "non-existent")
                genes[name] = second;
        else
        {
                if (children[second].first == "")
                    children[second].first = name;
                else
                    children[second].second = name;
                    
                // genes[second]
        }
    }
    
    for (int i = 0; i < children.size(); ++i)
        for (auto it = children.begin(); it != children.end(); ++it)
        {
            if (genes[it->second.first] == "non-existent" and genes[it->second.second] == "non-existent" or
                genes[it->second.first] == "recessive" and genes[it->second.second] == "non-existent" or
                genes[it->second.first] == "non-existent" and genes[it->second.second] == "recessive")
            {
                genes[it->first] = "non-existent";
            }
            if (genes[it->second.first] == "dominant" and genes[it->second.second] == "non-existent" or
                     genes[it->second.first] == "non-existent" and genes[it->second.second] == "dominant" or
                     genes[it->second.first] == "recessive" and genes[it->second.second] == "recessive")
            {
                genes[it->first] = "recessive";
            }
            if (genes[it->second.first] == "dominant" and genes[it->second.second] == "dominant" or
                genes[it->second.first] == "dominant" and genes[it->second.second] == "recessive" or
                genes[it->second.first] == "recessive" and genes[it->second.second] == "dominant")
            {
                genes[it->first] = "dominant";
            }
            // cout << it->first << ": " << genes[it->second.first] << " " << genes[it->second.second]<< '\n';
        }
    
    
    for (auto it = genes.begin(); it != genes.end(); ++it)
    {
        cout << it->first << " " << it->second << '\n';
    }
}