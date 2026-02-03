#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {

    // dist[i] = shortest distance from src to i
    vector<int> dist(n, INF);

    // Min-heap priority queue
    // Stores {distance, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // Distance of source from itself is 0
    dist[src] = 0;

    // Push source into pq
    pq.push({0, src});

    // While there are nodes to process
    while (!pq.empty()) {

        // Get node with smallest distance
        auto [d, u] = pq.top();
        pq.pop();

        // IMPORTANT CHECK:
        // If this distance is outdated (bigger than best known),
        // skip this entry
        if (d > dist[u])
            continue;

        // Relax all neighbors of u
        for (auto [v, wt] : adj[u]) {

            // If going through u gives a shorter path to v
            if (dist[v] > dist[u] + wt) {

                // Update shortest distance to v
                dist[v] = dist[u] + wt;

                // Push updated distance into pq
                pq.push({dist[v], v});
            }
        }
    }

    // dist array now contains shortest distances
    return dist;
}
