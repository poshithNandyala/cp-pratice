#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if(i == n - 1 && j == m - 1) continue;
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % 1000000007;
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
