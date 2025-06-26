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
        ll n, a, b;
        cin >> n >> a >> b;
        vector<ll> x(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> x[i];
            x[i] += x[i - 1];
        }
        ll ans = x[n] * b;
        for (ll i = 1; i <= n; i++)
        {
            ans = min(ans, ((x[i] - x[i - 1]) * (b + a)) + (((x[n] - x[i]) - (n - i) * (x[i] - x[i - 1]) )* b));
        }

        cout << ans << endl;
    }
}