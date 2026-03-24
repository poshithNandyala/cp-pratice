#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, m, k;
    cin >> n >> m >> k;
    vector < vector<pair<int, int>>> adj(n + 1);
    for (int i = 1;i <= m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({ v, wt });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq.push({ 0,1 });
    vector<int> dist(n + 1, 1e18);
    dist[1] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
            if (v == n) {
                pq2.push(dist[u] + w);
            }
        }
    }
    for (int i = 0;i < k;i++) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    return 0;
}
