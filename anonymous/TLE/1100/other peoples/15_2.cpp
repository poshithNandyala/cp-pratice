#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        s += s;
        ll maxi = 0, cnt = 0;
        for (ll i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else
            {
                cnt = 0;
            }
        }

        maxi = maxi == s.length() ? maxi / 2 : maxi;
        if (maxi == s.length() / 2)
            cout << ll(maxi * maxi) << endl;
        else
            cout << max(maxi, ll(ll(maxi + 1) * (maxi + 1)) / 4) << endl;
    }
    return 0;
}