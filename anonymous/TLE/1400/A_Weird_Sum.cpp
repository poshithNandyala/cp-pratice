#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio
        ll n,
        m;
    cin >> n >> m;
    map<ll, ll> mp;
    map<ll, vector<ll>> mprv, mpcv;
    ll a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]]++;
            mprv[a[i][j]].push_back(i);
            mpcv[a[i][j]].push_back(j);
        }
    }
    ll ans = 0;
    for (auto it : mprv)
    {
        if (it.second.size() > 1)
        {
            sort(it.second.begin(), it.second.end());
            ll sum = 0;
            for (int i = 0; i < it.second.size(); i++)
            {
                ans += i * it.second[i] - sum;
                sum += it.second[i];
            }
        }
    }
    for (auto it : mpcv)
    {
        if (it.second.size() > 1)
        {
            sort(it.second.begin(), it.second.end());
            ll sum = 0;
            for (int i = 0; i < it.second.size(); i++)
            {
                ans += i * it.second[i] - sum;
                sum += it.second[i];
            }
        }
    }
    cout << ans << endl;
}