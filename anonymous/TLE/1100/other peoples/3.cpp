#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    vector<int> ans(n), pre(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end(), greater<>());
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[n - i].first;
    ans[a[0].second] = n - 1;
    for (int i = 1; i < n; i++)
    {
        ans[a[i].second] = n - i - 1;
        if (pre[n - i] >= a[i - 1].first)
            ans[a[i].second] = ans[a[i - 1].second];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(0);
    cout.tie(nullptr)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}