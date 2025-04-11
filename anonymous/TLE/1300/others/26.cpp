#include <bits/stdc++.h>
#define ll long long int

using namespace std;
int main()
{
    string s;
    cin >> s;
    ll a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'o')
        {
            b += a;
        }
        else if (i > 0 && s[i - 1] == 'v')
        {
            a++;
            c += b;
        }
    }
    cout << c << "\n";
}