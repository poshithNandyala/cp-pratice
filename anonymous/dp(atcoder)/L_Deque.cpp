#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int  rec(int l, int r, vector<int>& a, vector<vector<int>>& dp) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ans = 0;
    if (l == r) {
        ans = a[l];
    }
    else {
        ans = max(a[l] - rec(l + 1, r, a, dp), a[r] - rec(l, r - 1, a, dp));
    }
    return dp[l][r] = ans;
}

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = rec(0, n - 1, a, dp);
    cout << ans << endl;
    return 0;
}
