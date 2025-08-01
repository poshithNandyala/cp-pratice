#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

vector<int> g[N];   // red-edge only graph
bool vis[N];

// Fast exponentiation: (a^b) % m
int modpow(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// DFS to find size of red component
int dfs(int u) {
    vis[u] = true;
    int sz = 1;
    for (int v : g[u]) {
        if (!vis[v])
            sz += dfs(v);
    }
    return sz;
}

int32_t main() {
    fastio

        int n, k;
    cin >> n >> k;

    // Clear previous test case data
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = false;
    }

    // Read edges
    for (int i = 1; i <= n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if (x == 0) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    // Total sequences
    int total = modpow(n, k, MOD);
    // Subtract all bad sequences (inside red-only components)
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int comp_size = dfs(i);
            total = (total - modpow(comp_size, k, MOD) + MOD) % MOD;
        }
    }
    cout << total << endl;

    return 0;
}
