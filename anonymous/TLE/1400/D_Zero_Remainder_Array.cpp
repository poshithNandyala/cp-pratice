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
        unordered_map<ll, ll> mp;
        ll mx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % k)
            {
                mx = max(mx, ++mp[k - (a[i] % k)]);
            }
        }
        ll ans = -1;
        for (auto it : mp)
        {
            if (it.second == mx)
            {
                ans = max(ans, it.first);
            }
        }
        if(mp.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        cout << (mx - 1) * k + ans + 1 << endl;
    }
}