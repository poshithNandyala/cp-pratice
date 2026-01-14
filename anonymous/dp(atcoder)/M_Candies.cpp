#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int rec(int i, vector<int>& a, int n, int k, vector<vector<int>>& dp) {
    if (k == 0) return 1;
    if (i == n) return 0;
    if (dp[i][k] != -1) return dp[i][k];
    int ans = 0;
    for (int j = 0;j <= a[i];j++) {
        if (j > k) break;
        ans = (ans + rec(i + 1, a, n, k - j, dp)) % 1000000007;
    }
    return dp[i][k] = ans;
}

int32_t main() {
    fastio
        int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    // cout << rec(0, a, n, k, dp) << endl;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0;i <= n;i++) {
        dp[i][0] = 1;
    }
    for (int i = 0;i < n;i++) {
        int ans = 0;
        for (int j = 0;j <= a[i];j++) {
            if (j > k) break;
            ans = (ans + dp[i - 1][k - j]) % 1000000007;
            dp[i][j] = ans;
        }
    }
    cout << dp[0][k] << endl;
    return 0;
}
