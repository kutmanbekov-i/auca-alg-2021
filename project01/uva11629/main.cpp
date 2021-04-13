#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, g, a, b;
    string line, w;
    char party[21];
    double percent;
    cin >> g >> p;
    
    unordered_map <string, int> parties;
    
    while (g--)
    {
        scanf("%s %d.%d", party, &a, &b);
        parties[party] = a * 10 + b;
    }
    
    getline(cin, line);
    for (int j = 1; j <= p; ++j)
    {
        getline(cin, line);
        
        istringstream sinp(line);
        
        int sum = 0, num;
        string sign;
        bool number = false;
        bool correct = false;
        
        while (sinp >> w)
        {
            if (number)
            {
                num = stoi(w) * 10;
                if (sign == ">")
                    correct = sum > num;
                
                else if (sign == "<")
                    correct = sum < num;
                
                else if (sign == ">=")
                    correct = sum >= num;
                
                else if (sign == "<=")
                    correct = sum <= num;
                
                else if (sign == "=")
                {
                    correct = sum == num;
                }
            }
            if (w == "+")
            {
                // continue;
            }
            else if (w == ">" or w == "<" or w == ">=" or w == "<=" or w == "=") {
                number = true;
                sign = w;
                // cout << w << "\n";
            }
            else {
                sum += parties[w];
            }
        }
        
        cout << "Guess #" << j << " was " << (correct ? "correct." : "incorrect.") << '\n';
        // cout << sum << sign << num << '\n';
    }
}