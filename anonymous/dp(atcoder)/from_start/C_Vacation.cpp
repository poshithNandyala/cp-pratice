#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    int n;
    cin >> n;
    vector < vector<int>> a(n, vector<int>(3));
    for (int i = 0;i < n;i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    vector<vector<int>> dp(n, vector<int>(3));
    dp[n - 1][0] = max(a[n - 1][1], a[n - 1][2]);
    dp[n - 1][1] = max(a[n - 1][0], a[n - 1][2]);
    dp[n - 1][2] = max(a[n - 1][0], a[n - 1][1]);
    for (int i = n - 2;i >= 0;i--) {
        dp[i][0] = max(a[i][1] + dp[i + 1][1], a[i][2] + dp[i + 1][2]);
        dp[i][1] = max(a[i][0] + dp[i + 1][0], a[i][2] + dp[i + 1][2]);
        dp[i][2] = max(a[i][0] + dp[i + 1][0], a[i][1] + dp[i + 1][1]);
    }
    cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << endl;
    return 0;
}