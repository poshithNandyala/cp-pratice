#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> vis;
int start = -1, endd = -1;

bool dfs(int u, int par) {
    vis[u] = true;

    for (int v : adj[u]) {
        if (v == par) continue;

        if (vis[v]) {
            start = v;
            endd = u;
            return true;
        }

        parent[v] = u;
        if (dfs(v, u)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    parent.assign(n + 1, -1);
    vis.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct cycle
    vector<int> path;
    path.push_back(start);

    int cur = endd;
    while (cur != start) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (int x : path) cout << x << " ";
    cout << endl;
}