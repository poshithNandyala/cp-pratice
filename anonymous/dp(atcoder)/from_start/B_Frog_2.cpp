#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int t = 1;
    // cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> dp(n,0);
        for (int i = n - 2;i >= 0;i--) {
            int mi = INT_MAX;
            for (int j = i + 1;j < min(i + k+1, n);j++) {
                mi=min(mi,(abs(a[i]-a[j])+dp[j]));
            }
            dp[i] = mi;
        }
        cout << dp[0] << endl;
    }
}
