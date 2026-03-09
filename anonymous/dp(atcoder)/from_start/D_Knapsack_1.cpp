#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int rec(vector<int>& val, vector<int>& wt, int n, int w, vector<vector<int>>& dp) {
    if (n == 0 || w == 0) return 0;

    if (dp[n][w] != -1) return dp[n][w];

    if(wt[n-1]<=w) {
        return  dp[n][w] = max(val[n-1]+rec(val, wt, n-1, w-wt[n-1],dp), rec(val, wt, n-1, w,dp));
    } else {
        return dp[n][w] = rec(val, wt, n-1, w,dp);
    }
    
}

int32_t main() {
    fastio
    int t=1;
    // cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector<int> val(n), wt(n);
        for(int i=0;i<n;i++){
            cin >> wt[i] >> val[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        int ans = rec(val, wt, n, w,dp);
        cout << ans << endl;
    }
}
