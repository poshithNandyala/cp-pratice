#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
ll n, m, k;
vector<ll> a, b;

bool check(ll mid)
{
    ll ans = 0;
    for (ll i = 0; i < m; i++)
    {
        ll j = upper_bound(a.begin(), a.end(), mid - b[i]) -   a.begin();
        ans += j;
    }
    return ans>=k;
}
int main()
{
    fastio ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        a.resize(n);
        b.resize(m);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll ans = 0;
        if (n < m)
        {
            swap(n, m);
            swap(a, b);
        }
        ll low = a[0] + b[0], high = a[n - 1] + b[m - 1];

        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (check(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
}