#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int rec(int i, vector<pair<int, int>>& a, int n, int w, vector<vector<int>>& dp) {
    if (i == n) return 0;
    if (dp[i][w] != -1) return dp[i][w];
    if (a[i].first <= w) {
        return dp[i][w] = max(a[i].second + rec(i+1, a, n, w-a[i].first, dp), rec(i+1, a, n, w, dp));
    }
    return dp[i][w] = rec(i+1, a, n, w, dp);
}
int32_t main() {
    fastio
        int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<vector<int>> dp(n,vector<int> (w+1, -1));
    cout << rec(0, a, n, w,dp) << endl;
    return 0;
}
