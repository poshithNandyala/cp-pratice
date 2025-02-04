#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
inline void solve()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    ll sum = 1;
    for (int i = 1; i <= n; i++)
    {
        int idx = lower_bound(b + 1, b + n + 1, a[i]) - b;
        sum = sum * (idx - i) % MOD;
    }
    if (sum < 0)
        sum += MOD;
    cout << sum << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}