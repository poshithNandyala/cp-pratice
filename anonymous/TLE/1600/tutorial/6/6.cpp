#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of people in this test case

        vector<int> a(n); // a[i] = neighbor remembered by person i
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--; // Convert to 0-based indexing
        }

        // Build an undirected graph
        // g[i] stores all neighbors of person i
        vector<set<int>> g(n);
        for (int i = 0; i < n; i++) {
            g[i].insert(a[i]); // edge i -> a[i]
            g[a[i]].insert(i); // edge a[i] -> i (undirected)
        }

        // Compute degree of each node
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = g[i].size(); // Number of unique neighbors
        }

        vector<bool> vis(n, false); // Keep track of visited nodes during BFS
        int c = 0;   // Count of components which are cycles
        int nc = 0;  // Count of components which are not cycles (bamboos)

        // Loop through all nodes to explore each component
        for (int i = 0; i < n; i++) {
            if (!vis[i]) { // If node i is not visited, it's a new component
                queue<int> q;
                q.push(i);      // Start BFS from node i
                vis[i] = true;

                vector<int> component = { i }; // Store all nodes in this component

                // BFS to traverse the whole component
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : g[u]) { // Explore neighbors
                        if (!vis[v]) {   // If neighbor not visited
                            vis[v] = true; // Mark it visited
                            q.push(v);     // Add to BFS queue
                            component.push_back(v); // Add to component
                        }
                    }
                }

                // Check if this component is a bamboo (has at least one degree-1 node)
                bool flag = false;
                for (int u : component) {
                    if (d[u] == 1) { // Node with degree 1
                        flag = true;
                        break;
                    }
                }

                if (flag) { // Component is a bamboo
                    nc++;
                } else {    // Component is a cycle
                    c++;
                }
            }
        }

        // Minimum number of dances: all cycles + 1 if there is any bamboo
        // Maximum number of dances: all cycles + all bamboos
        cout << c + min(nc, 1LL) << " " << c + nc << endl;
    }

    return 0;
}
