#include <bits/stdc++.h>

using namespace std;

string rule;

int num_words;

vector<string> words(101);
static vector<string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

vector<string> outputs(256);

void solve(int index)
{
    if (index == rule.size())
    {
        for (int i = 0; i < index; ++i)
            cout << outputs[i];
        cout << '\n';
    }
    else
    {
        if (rule[index] == '#')         // word
        {
            for (int i = 0; i < num_words; ++i)
            {
                outputs[index] = words[i];
                solve(index + 1);
            }
        }
        else if (rule[index] == '0')    // number
        {
            for (size_t i = 0; i < numbers.size(); ++i)
            {
                outputs[index] = numbers[i];
                solve(index + 1);
            }
        }
    }
}


int main()
{
    while (cin >> num_words)
    {
        for (int i = 0; i < num_words; ++i)
        {
            cin >> words[i];
        }
        
        int num_rule; cin >> num_rule;
        
        cout << "--\n";
        while (num_rule--)
        {
            cin >> rule;
            solve(0);
        }
    }
}