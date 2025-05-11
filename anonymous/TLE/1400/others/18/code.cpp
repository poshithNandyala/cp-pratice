#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define ld long double

const ll MOD = 1e9 + 7;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m = INT32_MAX, p = 1;
        cin >> n;
        map<ll, ll> f;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            f[x]++;
            m &= x;
        }
        for (ll i = 2; i < n - 1; i++)
        {
            p *= i;
            p %= MOD;
        }
        cout << 2 * (((f[m] * (f[m] - 1) / 2) % MOD) * p) % MOD << "\n";
    }

    return 0;
}