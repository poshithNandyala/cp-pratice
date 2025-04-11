#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            for (char x = 'a'; x <= 'z'; x++)
            {
                if (x != s[i + 1] && x != s[i - 1])
                {
                    cout << x;
                    s[i] = x;
                    break;
                }
            }
        }
        else
            cout << s[i];
    }
}