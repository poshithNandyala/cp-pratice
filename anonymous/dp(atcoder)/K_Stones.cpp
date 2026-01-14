#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);



bool rec(vector<int>& dp, vector<int>& a, int k) {
    if (k == 0) return false;
    if (dp[k] != -1) return dp[k];
    for (int j = 0;j < a.size();j++) {
        if (a[j] > k) continue;
        if (!rec(dp, a, k - a[j])) {
            return dp[k] = true;
        }
    }
    return dp[k] = false;
}

int32_t main() {
    fastio
        int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // vector<int> dp(k + 1, -1);
    // if (rec(dp, a, k)) {
    //     cout << "First" << endl;
    //     return 0;
    // }
    // cout << "Second" << endl;
    vector<bool> dp(k + 1, false);
    dp[0] = false;
    for (int i = 1; i <= k; i++) {
        for (int j = 0;j < a.size();j++) {
            if ((i >= a[j]) && !dp[i - a[j]]) {
                dp[i] = true;
                break;
            }
        }
    }
    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
