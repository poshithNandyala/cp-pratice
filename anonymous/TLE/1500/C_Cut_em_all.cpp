#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

vector<vector<int>> adj;
vector<int> subtree_size;
int cuts = 0;

void dfs(int node, int par) {
    subtree_size[node] = 1;
    
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
            
            if (subtree_size[child] % 2 == 0) {
                cuts++;
            }
        }
    }
}

int32_t main() {
    fastio
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    subtree_size.resize(n + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    dfs(1, -1);
    
    cout << cuts << endl;
    
    return 0;
}
