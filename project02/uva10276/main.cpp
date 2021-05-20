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
        
        for (int i = 1; ; ++i)
        {
            int index = 1, sqrt_v = 0, value = 0;
            
            while (pegs[index] and index <= n) {
                value = pegs[index] + i;
                sqrt_v = (int)sqrt(value + 0.1);
                if (sqrt_v*sqrt_v == value)
                {
                    pegs[index] = i;
                    break;
                } else
                {
                    index++;
                }
            }
            //printf("index [%d] : %d\n", index, i);
            if (index > n)
            {
                printf("%d\n", i-1);
                break;
            } else {
                pegs[index] = i;
            }
        }
        
        
    }

}