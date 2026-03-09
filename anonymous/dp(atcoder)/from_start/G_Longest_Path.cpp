#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);


void dfs(int node, vector<vector<int>>& adj, vector<int>& dp){
    if (dp[node] != -1) return;
    dp[node] = 0;
    for (auto it : adj[node]) {
        dfs(it, adj, dp);
        dp[node] = max(dp[node], dp[it] + 1);
    }
}

int32_t main() {
    fastio
        int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> dp(n + 1, -1);
    for (int i = 1;i <= n;i++) {
        if(dp[i] == -1) dfs(i, adj, dp);
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
    return 0;
}
