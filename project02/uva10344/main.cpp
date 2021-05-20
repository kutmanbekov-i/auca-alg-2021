#include <bits/stdc++.h>

using namespace std;

bool Possible(vector<int> &v, int sum, int index)
{
    if (index == 5)
        return sum == 23;
    
    int num = v[index];
    
    return Possible(v, sum + num, index + 1) 
        or Possible(v, sum - num, index + 1)
        or Possible(v, sum * num, index + 1);
}

int main()
{
    
    while (2 + 2 != 5)
    {
        vector<int> v(5);
        bool end = true;
        
        for (int i = 0; i < 5; ++i)
        {
            cin >> v[i];
            if (v[i] != 0)
                        end = false;
        }
        
        if (end) break;
        
        sort(v.begin(), v.end());
        
        bool possible = false;
        do {
            possible = Possible(v, v[0], 1);
            
            if (possible)
                break;
        } while (next_permutation(v.begin(), v.end()));
        
        if (possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}