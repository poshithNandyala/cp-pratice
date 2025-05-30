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
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    map<ll, ll> mp;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i] - i] += a[i];
        ans = max(ans, mp[a[i] - i]);
    }
    cout << ans << endl;
}