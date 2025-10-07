#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

bool rec(int i, int j, int n, const vector<int>& a, vector<int>& dp) {
    if (i == j && dp[i] != -1) return dp[i];
    if (i == n && j == n) {
        if (i == j) dp[i] = 1;
        return true;
    }
    if (j >= n) return false;
    bool res = false;
    if (i < n && j < n && (a[i] == (j - i) || a[j] == (j - i))) {
        res = rec(j + 1, j + 1, n, a, dp) || rec(i, j + 1, n, a, dp);
    } else {
        res = rec(i, j + 1, n, a, dp);
    }
    if (i == j) dp[i] = res ? 1 : 0;
    return res;
}

int32_t main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> dp(n + 1, -1);
        cout << (rec(0, 0, n, a, dp) ? "YES\n" : "NO\n");
    }
}
