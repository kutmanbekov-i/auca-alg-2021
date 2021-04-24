#include <bits/stdc++.h>

using namespace std;

// C(n, h) = n! / ( h! * (n - h)! )

void solve(string temp, int n, int h)
{
    if ((int)temp.size() == n) {
		if (!h)
			cout << temp << '\n';
		return;
	}
	solve (temp + '0', n, h);
	        // here the value of temp is still "000", we're just calling a func for ("0000", 4, 2)
	solve (temp + '1', n, h - 1);   // then it returns here, and calls the func for ("0001", 4, 1)
	                                // then it return to "00" and calls the func for ("001", 4, 1), then for ("0010", 4, 1)  and ("0011", 4, 0) respectively
	                                // then it return to "0"  and calls the func for ("01", 4, 1), then ("010", 4, 1) - метка что не проверили ("011", 4, 0), then ("0100", 4, 1) and ("0101, 4, 0")
	                                // then go to "метка", and call ("011", 4, 0), then ("0110", 4, 0)
	                                
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    
    while (t--)
    {
        int n, h;
        cin >> n >> h;

        string temp;
        
        solve (temp, n, h);

        if (t)
                cout << '\n';
    }
}