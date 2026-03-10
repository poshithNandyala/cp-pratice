#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);


double rec(int i, int h, vector<double>& a, vector<vector<double>>& dp) {

    if (i == a.size()) {
        if (h > a.size() - h) return 1;
        else return 0;
    }

    if(dp[i][h] != -1) return dp[i][h];


    double ans = 0;

    
    ans += (a[i] * rec(i + 1, h + 1, a,dp));

    ans += ((1 - a[i]) * rec(i + 1, h, a,dp));

    return dp[i][h] = ans;
}


int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
    double ans = rec(0, 0, a,dp);
    cout << fixed << setprecision(10) << ans << endl;

}
