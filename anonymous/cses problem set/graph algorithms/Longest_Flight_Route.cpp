#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int n, m;

// returns max path length from node i to n
int dfs(int i, vector<vector<int>>& adj, vector<int>& dp, vector<int>& par) {
    
    if (i == n) return 1; // reached destination

    if (dp[i] != -1) return dp[i];

    int ans = -1e9;

    for (auto it : adj[i]) {
        int val = dfs(it, adj, dp, par);

        if (val > 0 && ans < val + 1) {
            ans = val + 1;
            par[i] = it; // store next node
        }
    }

    return dp[i] = ans;
}

int32_t main() {
    fastio

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> dp(n + 1, -1);
    vector<int> par(n + 1, -1);

    int res = dfs(1, adj, dp, par);

    if (res < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << res << "\n";

    // reconstruct path
    vector<int> path;
    int cur = 1;

    while (cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }

    for (int x : path) cout << x << " ";
}