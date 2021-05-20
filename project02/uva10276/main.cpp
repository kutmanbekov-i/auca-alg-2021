#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;  cin >> t;
    
    while (t--)
    {
        int n; cin >> n;
        
        vector<int> pegs(n, 0);
        // solve(n);
        int i, j, tmp;
        
        pegs[0] = 1;
        for(i = 2; ; i++)
        {
            for(j = 0; j < n; j++)
            {
                tmp = pegs[j] + i;
                tmp = (int)sqrt(tmp);
                if (tmp * tmp == pegs[j] + i or pegs[j] == 0)
                {
                    pegs[j] = i;
                    break;
                }
            }
            if (j == n)  break;
        }
        printf("%d\n", i - 1);
    }
}