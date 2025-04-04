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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n + 1), b(m + 1);
        a[0] = 1000000000;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        b[0] = 0;
        for (ll i = 1; i <= m; i++)
        {
            cin >> b[i];
        }
        ll i = 1;
        ll j = 1;
        ll ans = 0;
        while (i <= n)
        {
            if (j < a[i])
            {
                ans += b[j++];
            }
            else{
                ans+=b[a[i]];
            }
            i++;
        }
        cout << ans << endl;
    }
}