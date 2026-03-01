#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);


int dfs(int node, vector<vector<int>>& adj, int parent) {
    int ans = 1;
    for (auto it : adj[node]) {
        if (it != parent) {
            ans = max(ans, 1 + dfs(it, adj, node));
        }
    }
    return ans;
}
int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> src;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        int v = i;
        if (u == -1) src.push_back(v);
        else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


    }
    int ans = 1;
    for (auto it : src) {
        ans = max(ans, dfs(it, adj, -1));
    }
    cout << ans << endl;
}
