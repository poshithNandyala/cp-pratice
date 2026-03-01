#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);


void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    for(auto it:adj[u]) {
        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

int32_t main() {
    fastio
        int n, t;
    cin >> n >> t;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        adj[i].push_back(i+a);
    }
    vector<bool> vis(n + 1, false);
    dfs(1,adj,vis);
    if(vis[t]) cout<<"YES" << endl;
    else cout<<"NO" << endl;

}
