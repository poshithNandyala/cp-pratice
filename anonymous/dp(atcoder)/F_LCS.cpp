#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int rec(string &s, string &t, int i, int j, vector<vector<int>>& dp) {
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i - 1] == t[j - 1]) return dp[i][j] = 1 + rec(s, t, i - 1, j - 1, dp);
    return dp[i][j] = max(rec(s, t, i - 1, j, dp), rec(s, t, i, j - 1, dp));
}
void lcs(string &s, string &t, int i, int j, vector<vector<int>>& dp, string& ans) {
    if (i == 0 || j == 0) return;
    if (s[i - 1] == t[j - 1]) {
        ans += s[i - 1];
        lcs(s, t, i - 1, j - 1, dp, ans);
    }
    else if (dp[i - 1][j] >= dp[i][j - 1]) {
        lcs(s, t, i - 1, j, dp, ans);
    }
    else if (dp[i][j - 1] > dp[i - 1][j]) {
        lcs(s, t, i, j - 1, dp, ans);
    }
}
int32_t main() {
    fastio
        string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    rec(s, t, n, m, dp);
    string ans = "";
    lcs(s, t, n, m, dp, ans);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
