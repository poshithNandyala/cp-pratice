#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, sizev;

public:
    DSU(int n) {
        parent.resize(n);
        sizev.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by size
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        // attach smaller tree under larger tree
        if (sizev[px] < sizev[py])
            swap(px, py);

        parent[py] = px;
        sizev[px] += sizev[py];
    }

    // optional helper
    int size(int x) {
        return sizev[find(x)];
    }
};