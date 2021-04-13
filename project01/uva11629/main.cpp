#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int p, g;
    string party, line, w;
    double percent;
    cin >> g >> p;
    
    unordered_map <string, double> parties;
    
    while (g--)
    {
        cin >> party >> percent;
        parties[party] += percent;
    }
    
    getline(cin, line);
    for (int j = 1; j <= p; ++j)
    {
        getline(cin, line);
        
        istringstream sinp(line);
        
        double sum = 0, num;
        // int num;
        string sign;
        bool number = false;
        bool correct = false;
        
        while (sinp >> w)
        {
            if (number)
            {
                num = stof(w);
                // double intpart;
                // modf(sum, &intpart) == 0.0;
                // sum = intpart;
                // ssum = to_string(sum);
                
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