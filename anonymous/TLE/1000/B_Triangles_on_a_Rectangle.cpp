#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio ll t;
    cin >> t;
    while (t--)
    {
        ll w, h;
        cin >> w >> h;
        ll ans = 0;
        for (ll i = 0; i < 4; i++)
        {
            ll mi, ma;
            ll n;
            cin >> n;
            cin >> mi;
            for (ll i = 1; i < n - 1; i++)
            {
                ll x;
                cin >> x;
            }
            cin >> ma;
            ma -= mi;
            if (i < 2)
            {
                ma *= h;
            }
            else
            {
                ma *= w;
            }
            ans = max(ans, ma);
        }
        cout << ans << endl;
    }
}