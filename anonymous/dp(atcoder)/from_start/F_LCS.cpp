#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int lcs(string s, string t, int i, int j, vector<vector<int>>& dp) {

    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) return dp[i][j] = 1 + lcs(s, t, i - 1, j - 1, dp);
    else return dp[i][j] = max(lcs(s, t, i - 1, j, dp), lcs(s, t, i, j - 1, dp));
}



int32_t main() {
    fastio
        string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    lcs(s, t, n - 1, m - 1, dp);
    string ans = "";
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) ans.append(1, s[i]), i--, j--;
        else {
            int left = (j > 0) ? dp[i][j - 1] : 0;
            int up = (i > 0) ? dp[i - 1][j] : 0;

            if (left > up) j--;
            else i--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
