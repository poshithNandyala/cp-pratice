#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n);
    dp[n - 1] = 0;
    dp[n - 2] = abs(a[n - 1] - a[n - 2]);
    for (int i = n - 3; i >= 0; i--) {
        dp[i]=min(abs(a[i]-a[i+1])+dp[i+1],abs(a[i]-a[i+2])+dp[i+2]);
    }
    cout << dp[0] << endl;
    return 0;
}
