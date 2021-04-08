#include <bits/stdc++.h>

using namespace std;

int code;
map <string, int> m;

void generate_code(string s, size_t len)
{
    if (s.size() == len)
    {
        m[s] = code++;
        return;
    }
    char last;
    if (s.empty())
        last = 'a';
    else
        last = s[s.size() - 1] + 1;

    for (char c = last; c <= 'z'; ++c)
        generate_code(s + c, len);
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    code = 1;
    
    for (int len = 1; len <= 5; ++len)
    {
        generate_code("", len);   
    }
    
    for (string word; cin >> word; )
    {
        cout << m[word] << '\n';
    }
}