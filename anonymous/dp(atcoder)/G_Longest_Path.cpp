#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);


int dfs(int node, vector<vector<int>> &adj, vector<int> &dp) {
    if (dp[node] != -1) return dp[node];
    int mx = 0;
    for (auto it : adj[node]) {
        mx = max(mx, 1 + dfs(it, adj, dp));
    }
    return dp[node] = mx;
}

int32_t main() {
    fastio
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int mx = 0;
    vector<int> dp(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dfs(i, adj, dp));
    }
    cout << mx << endl;

}
