#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    ll n1 = (n * (n + 1)) % mod;
    n1 = (n1 * (((4 * n) % mod) - 1)) % mod;

    cout << (337 * n1) % mod << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}