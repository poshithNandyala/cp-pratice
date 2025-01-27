#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

ll func(vector<ll> a, int n)
{
    if (n <= 1)
    {
        return -10000;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = (a[i + 1] - a[i]);
        ans += a[i];
    }
    ans = abs(ans);
    n -= 1;
    ll ans1 = max(func(a, n), ans);
    // reverse(a.begin(), a.begin() + n);
    // ll ans2 = func(a, n);
    return abs(ans1);
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ans += a[i];
        }
        ans = max(ans, func(a, n));
        // reverse(a.begin(), a.begin() + n);
        // ans = max(ans, func(a, n));
        if (n == 1)
        {
            cout << a[0] << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}
