#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, m;
    cin >> n >> m;
    vector<vector<int>>  adj(n + 1);
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    vector<int> ans;
    vector<bool> vis(n + 1, false);
    vis[1] = true;
    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for(auto v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                pq.push(v);
            }
        }
    }
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;


}
