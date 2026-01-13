#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < 3;j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(3,0));
    dp[n - 1] = a[n - 1];
    for (int i = (n - 2);i >= 0;i--) {
        dp[i][0] = max(dp[i + 1][1], dp[i + 1][2]) + a[i][0];
        dp[i][1] = max(dp[i + 1][0], dp[i + 1][2]) + a[i][1];
        dp[i][2] = max(dp[i + 1][0], dp[i + 1][1]) + a[i][2];
    }
    cout << max({dp[0][0], dp[0][1], dp[0][2]}) << endl;
    return 0;
}
