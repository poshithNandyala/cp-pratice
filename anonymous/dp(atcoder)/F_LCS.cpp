#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
string lcs(string s, string t, int i, int j, vector<vector<string>> &dp) {
    if (i == 0 || j == 0) return "";
    if (s[i - 1] == t[j - 1]) {
        if (dp[i - 1][j - 1] == "#") {
            dp[i - 1][j - 1] = lcs(s, t, i - 1, j - 1, dp);
        }
        return dp[i - 1][j - 1] + s[i - 1];
    }
    string s1 = lcs(s, t, i - 1, j, dp);
    string s2 = lcs(s, t, i, j - 1, dp);
    if (s1.size() >= s2.size()) return  dp[i][j] = s1;
    return dp[i][j] = s2;
}
int32_t main() {
    fastio
    string s, t;
    cin >> s >> t;
    vector<vector<string>> dp(s.size(), vector<string>(t.size(), "#"));
    cout << lcs(s, t, s.size(), t.size(), dp) << endl;
    return 0;
}
