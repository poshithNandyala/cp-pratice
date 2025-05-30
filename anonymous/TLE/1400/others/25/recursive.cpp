#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

ll n;
vector<ll> a, b;

ll ans(ll i, ll pos, ll sum)
{
    if (i == n - 1)
    {
        if (pos)
        {
            return sum + b[i];
        }
        return sum + a[i];
    }
    if (pos)
    {
        ll ans1 = ans(i + 1, 0, sum + b[i]);
        ll ans2 = ans(i + 1, 1, sum);
        return max(ans1, ans2);
    }
    ll ans1 = ans(i + 1, 1, sum + a[i]);
    ll ans2 = ans(i + 1, 0, sum);
    return max(ans1, ans2);
}
int main()
{
    fastio;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << max(ans(0, 0, 0), ans(0, 1, 0)) << endl;
}