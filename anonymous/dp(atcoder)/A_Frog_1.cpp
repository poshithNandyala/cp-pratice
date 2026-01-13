#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

//Memoization
int rec(int i, vector<int>& a, vector<int>& dp) {
    if (dp[i] != -1) return dp[i];
    int ans = 0;
    if (i + 1 < a.size()) {
        ans = abs(a[i] - a[i + 1]) + rec(i + 1, a, dp);
    }
    if (i + 2 < a.size()) {
        ans = min(ans, abs(a[i] - a[i + 2]) + rec(i + 2, a, dp));
    }
    return dp[i] = ans;
}


int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //memoization
    vector<int> dp(n, -1);
    cout << rec(0, a, dp) << endl;;

    //tabulation
    vector<int> dp(n, 0);
    dp[n - 1] = 0;
    dp[n - 2] = abs(a[n - 1] - a[n - 2]);
    for (int i = n - 3;i >= 0;i--) {
        dp[i] = min(abs(a[i] - a[i + 1]) + dp[i + 1], abs(a[i] - a[i + 2]) + dp[i + 2]);
    }
    cout << dp[0] << endl;



    //tabulation (space optimised)
    int last = 0, last2 = abs(a[n - 1] - a[n - 2]);
    for (int i = n - 3;i >= 0;i--) {
        int temp = last2;
        last2 = min(abs(a[i] - a[i + 1]) + last2, abs(a[i] - a[i + 2]) + last);
        last = temp;
    }
    cout << last2 << endl;
    return 0;
}
