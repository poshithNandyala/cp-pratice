#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int rec(int i, int val, int n, vector<pair<int, int>>& a, vector<vector<int>>& dp) {
    if (val == 0) return 0;
    if (i == n) return 1e15;
    if (dp[i][val] != -1) return dp[i][val];
    int ans = rec(i + 1, val, n, a, dp);
    if (val >= a[i].second) {
        ans = min(ans, a[i].first + rec(i + 1, val - a[i].second, n, a, dp));
    }
    return dp[i][val] = ans;
}

int32_t main() {
    fastio
        int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    int sum = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].second;
    }
    vector<int> ans;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    for (int i = sum;i >= 0;i--) {
        if (rec(0, i, n, a, dp) <= w) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
