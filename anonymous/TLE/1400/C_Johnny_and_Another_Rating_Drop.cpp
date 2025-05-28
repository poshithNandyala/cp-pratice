#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        n += 1;
        ll ans = 0;
        for (ll i = 0; i < 61; i++)
        {
            ll x = (1LL << i);
            if(n < x)
                break;
            ans += (((n + (x - 1)) / x)-1);
        }
        cout << ans << endl;
    }
}