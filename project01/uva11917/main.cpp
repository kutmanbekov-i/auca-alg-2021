#include <bits/stdc++.h>

using namespace std;

int main()
{
    int hours, t; cin >> t;
    string subject, subject_due, state;
    
    for (int k = 1; k <= t; ++k)
    {
        int n; cin >> n;
        
        unordered_map <string, int> jack_sparrow;
        
        while (n--)
        {
            cin >> subject >> hours;
            jack_sparrow[subject] = hours;
        }
        
        int hours_left;
        cin >> hours_left >> subject_due;
        
        if ( jack_sparrow[subject_due] == 0 or jack_sparrow[subject_due] > hours_left + 5)
        {
            state = "Do your own homework!";
        }
        else if (jack_sparrow[subject_due]  <= hours_left)
        {
            state = "Yesss";
        }
        else if (jack_sparrow[subject_due] <= hours_left + 5)
        {
            state = "Late";
        }
        cout << "Case " << k << ": " << state << '\n';
    }
}