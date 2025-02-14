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
        vector<vector<ll>> a(m);
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                ll x;
                cin >> x;
                a[j].push_back(x);
            }
        }
        for (ll i = 0; i < m; i++)
        {
            sort(a[i].begin(), a[i].end());
        }
        ll ans = 0;
        for (ll i = 0; i < m; i++)
        {
            for (ll j = n - 2; j >= 0; j--)
            {
                ans += (a[i][j + 1] - ((n - j - 1) * a[i][j]));
                a[i][j] += a[i][j + 1];
            }
        }
        // for (ll i = 0; i < m; i++)
        // {
        //     for (ll j = 0; j < n; j++)
        //         cout << a[i][j] << " ";
        //     cout << endl;
        // }
        cout << ans << endl;
    }
}
