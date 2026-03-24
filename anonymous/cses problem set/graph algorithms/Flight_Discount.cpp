#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, m;
    cin >> n >> m;
    vector < vector<pair<int, int>>> adj(2 * n + 2);
    for (int i = 1;i <= m;i++) {
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({ v, wt });
        adj[u+n].push_back({ v+n, wt });
        adj[u].push_back({ v + n, wt / 2 });
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({ 0,1 });
    vector<int> dist(2 * n + 2, 1e18);
    dist[1] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
    cout << dist[2*n] << endl;
    return 0;
}
