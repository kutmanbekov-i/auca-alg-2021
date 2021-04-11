#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string line;
    int t; cin >> t;

    getline(cin, line); // move to the second line

    for (int j = 0; j < t; ++j)
    {
        if (j)
            cout << '\n';
            
        getline(cin, line);     // blank line after each input

        //            item,  id's
    	unordered_map<int, set<int>> locks;
    	unordered_map<int, char> modes;
    	unordered_map<int, bool> seen;
        unordered_map<int, bool> ignored;
        
        char mode;
        int id, item;
        string state;
        
        while (getline(cin, line) and line != "#")
        {
            istringstream sinp(line);
            
            sinp >> mode >> id >> item;
            
    		if (ignored[id])
    		{
				state = "IGNORED";
			}
			else if (seen[item] and (mode == 'X' or modes[item] == 'X') and locks[item].size() - locks[item].count(id))     // if GRANTED and mode == 'X' and DIFFERENT Transactions
			{
				state = "DENIED";
				ignored[id] = true;
			}
			else
			{
				state = "GRANTED";
				if (mode == 'X' or modes[item] == 'X')
				{
					modes[item] = 'X';
				}
				else
				{
					modes[item] = 'S';
				}
				locks[item].insert(id);
				seen[item] = true;
			}
			cout << state << '\n';
        }
    }
}