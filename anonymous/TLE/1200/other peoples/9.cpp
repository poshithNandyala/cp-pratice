#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<int, int> frequency;
    set<ll> b;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        frequency[v[i]]++;
        b.insert(v[i]);
        b.insert(v[i] + 1);
    }
    ll ans = 0;
    ll last = 0;
    for (auto x : b)
    {
        ll c = frequency[x];
        ans += max(0LL, c - last);
        last = c;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
