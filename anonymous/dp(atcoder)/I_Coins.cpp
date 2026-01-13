#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

double rec(vector<double>& tails, int mx, int t, int i, vector<vector<double>>& dp) {
    if (i == tails.size()) {
        return 1;
    }
    if (dp[i][t] != -1) {
        return dp[i][t];
    }
    double ans = 0;
    if (t < mx) {
        ans += rec(tails, mx, t + 1, i + 1, dp) * tails[i];
    }
    ans += rec(tails, mx, t, i + 1, dp) * (1 - tails[i]);
    return dp[i][t] = ans;

}
int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<double> tails(n);
    for (int i = 0; i < n; i++) {
        cin >> tails[i];
    }
    int mx = (n - 1) / 2;
    vector<vector<double>> dp(n, vector<double>(mx + 1, -1));
    double ans = rec(tails, mx, 0, 0, dp);
    cout << fixed << setprecision(10) << 1 - ans << endl;
}
