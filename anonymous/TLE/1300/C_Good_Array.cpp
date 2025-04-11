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
        map<int, vector<int>>
            m;
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        m[a[i]].push_back(i);
    }
    // cout << sum << endl;
    map<int, int> mp;
    ll ans = 0;
    sort(a.begin(), a.end());
    for (ll i = 0; i < n - 1; i++)
    {
        if ((sum - a[i]-a[n-1]) == a[n - 1])
        {
            mp[a[i]]++;
            ans++;
        }
    }
    if ((sum - a[n - 1]-a[n-2]) == a[n - 2])
    {
        mp[a[n - 1]]++;
        ans++;
    }
    cout << ans << endl;
    for (auto item : mp)
    {
        for (auto it : m[item.first])
        {
            cout << it + 1 << " ";
        }
    }
    cout << endl;
}