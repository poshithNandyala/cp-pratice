#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

//memoziation
int rec(int i, int n, int k, vector<int>& a, vector<int>& dp) {
    if (i >= n) return INT_MAX;
    if (i == n-1) return dp[n-1]=0;
    if (dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i + j < n) {
            ans = min(ans, abs(a[i + j] - a[i]) + rec(i + j, n, k, a, dp));
        }
    }
    return dp[i] = ans;
}

int32_t main() {
    fastio
        int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // vector<int> dp(n, -1);
    // int ans = rec(0, n, k, a, dp);
    // cout << ans << endl;

    //tabulation
    vector<int> dp(n, 0);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int ans = LLONG_MAX;
        for (int j = 1; j <= k; j++) {
            if (i + j < n) {
                ans = min(ans, abs(a[i + j] - a[i]) + dp[i + j]);
            }
        }
        dp[i] = ans;
    }

    cout << dp[0] << endl;
    
    return 0;
}
