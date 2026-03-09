#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int f(int n, int target, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (target == 0) return 0;
    if (n == -1) return 1e16;

    if (dp[n][target] != -1) return dp[n][target];

    int mi = f(n - 1, target, wt, val,dp); // not take
    if (val[n] <= target) mi =min(mi, f(n - 1, target - val[n], wt, val,dp) + wt[n]); // take 
    return dp[n][target] = mi;
}

int32_t main() {
    fastio

    int n, w;
    cin >> n >> w;
    vector<int> val(n), wt(n);
    int sum = 0;
    for (int i = 0;i < n;i++) {
        cin >> wt[i] >> val[i];
        sum += val[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    for (int i = sum;i >= 0;i--) {
        if (f(n-1, i, wt, val,dp) <= w) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

}

