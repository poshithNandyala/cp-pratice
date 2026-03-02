#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> dp(n + 1, 0);
        dp[n] = a[n];
        int ans = a[n];
        for (int i = n - 1; i >= 1; i--) {
            if (i + a[i] <= n) {
                dp[i] = a[i] + dp[i + a[i]];
            }
            else {
                dp[i] = a[i];
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}
