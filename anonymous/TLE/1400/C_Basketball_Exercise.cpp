#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

ll n;
vector<ll> a, b;
ll dp[100005][2];

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
    ll ans1 = sum, ans2 = sum;
    if (!dp[i + 1][pos])
    {
        dp[i + 1][pos] = ans(i + 1, pos, 0);
    }
    if (!dp[i + 1][!pos])
    {
        dp[i + 1][!pos] = ans(i + 1, !pos, 0);
    }
    if (pos)
    {

        ans1 = dp[i + 1][!pos] + b[i];
        ans2 = dp[i + 1][pos];
        return max(ans1, ans2);
    }
    ans1 = dp[i + 1][!pos] + a[i];
    ans2 = dp[i + 1][pos];
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