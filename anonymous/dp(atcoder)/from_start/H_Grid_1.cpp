#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int dfs(string s[], int i, int j, int n, int m, vector<vector<int>>& dp) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == n && j == m) return dp[i][j] = 1;

    int ans = 0;
    if (i + 1 <= n && s[i + 1][j] == '.') ans = (ans + dfs(s, i + 1, j, n, m, dp)) % (int)(1e9 + 7);
    if (j + 1 <= m && s[i][j + 1] == '.') ans = (ans + dfs(s, i, j + 1, n, m, dp)) % (int)(1e9 + 7);
    return dp[i][j] = ans;
}

int32_t main() {
    fastio
        int n, m;
    cin >> n >> m;
    string grid[n];
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << dfs(grid, 0, 0, n - 1, m - 1, dp) << endl;

}
