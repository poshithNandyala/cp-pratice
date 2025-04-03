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
        ll n, w;
        cin >> n >> w;
        vector<ll> a(n);
        vector<ll> mp(21, 0);

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            for (ll j = 0; j < 21; j++)
            {
                if ((a[i] & (1 << j)))
                {
                    mp[j]++;
                    break;
                }
            }
        }
        // for (auto item : mp)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";
        ll ans = 1;
        while (--n)
        {
            ll cnt = w;
            for (ll i = 20; i >= 0; i--)
            {
                if ((mp[i] && cnt) && ((1 << i) <= cnt))
                {
                    ll v= min(mp[i], (cnt / (1 << i)));
                    mp[i] -= v;
                    cnt -= (v) * (1 << i);
                }
            }
            // for (auto item : mp)
            // {
            //     cout << item << " ";
            // }
            // cout << "\n";
            bool flag = true;
            for (ll i = 20; i >= 0; i--)
            {
                if (mp[i] > 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
            ans++;
        }
        cout << ans << endl;
    }
}