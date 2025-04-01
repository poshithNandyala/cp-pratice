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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<ll> m(31, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            for (int j = 0; j < 31; j++)
            {
                if (!(a[i] & (1 << j)))
                {
                    m[j]++;
                }
            }
        }
        ll ans = 0;
        for (ll i = 30; i >= 0; i--)
        {
            if (m[i] <= k)
            {
                ans += (1 << i);
                k -= m[i];
            }
        }
        cout << ans << endl;
    }
}