#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = n + 1, c = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && c + a[j] <= s)
        {
            c += a[j];
            j++;
        }
        if (c == s)
            ans = min(ans, n - (j - i));
        c -= a[i];
    }
    if (ans > n)
        ans = -1;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}