#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> v;
        map<int, int> cur;
        auto it = cur.begin();
        
        int maxi = 0, u = 0;
        
        for (int i = 1; i <= n; ++i)
        {
			int x; cin >> x;
			
			int &r = cur[x];
			if (r > u)
			{
				maxi = max(maxi, i - u - 1);
				u = r;
			}
			r = i;
		} 
		maxi = max(maxi, n - u);
		cout << maxi << '\n';
    }
}