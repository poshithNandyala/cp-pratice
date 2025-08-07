#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

vector<vector<int>> adj;        // Adjacency list representation of tree
vector<int> subtree_size;       // Size of subtree rooted at each node
int cuts = 0;                   // Counter for maximum removable edges

void dfs(int node, int par) {
    subtree_size[node] = 1;     // Current node contributes 1 to subtree size
    
    for (int child : adj[node]) {
        if (child != par) {     // Avoid going back to parent
            dfs(child, node);   // Recursively calculate child's subtree
            subtree_size[node] += subtree_size[child];  // Add child's subtree size
            
            // Key insight: If child's subtree has even size, we can cut the edge
            // between current node and child, creating a valid even-sized component
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
    
    // Read tree edges and build adjacency list
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);    // Undirected edge: u -> v
        adj[v].push_back(u);    // Undirected edge: v -> u
    }
    
    // Critical check: If total nodes is odd, impossible to split into even components
    // Because sum of all component sizes = n, and sum of even numbers is even
    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    // Start DFS from any node (we choose node 1) to calculate subtree sizes
    // and count removable edges
    dfs(1, -1);
    
    // Output the maximum number of edges that can be removed
    cout << cuts << endl;
    
    return 0;
}
