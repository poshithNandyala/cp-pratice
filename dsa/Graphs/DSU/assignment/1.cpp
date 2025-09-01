#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

struct DSU {
    vector<int> par, sz;
    DSU(int n) {
        par.resize(n+1);
        sz.assign(n+1, 1);
        for (int i = 1; i <= n; i++) par[i] = i;
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

long long modpow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    DSU dsu(N);

    for (int q = 0; q < K; q++) {
        int l, r;
        cin >> l >> r;
        while (l < r) {
            dsu.merge(l, r);
            l++;
            r--;
        }
    }

    unordered_set<int> leaders;
    for (int i = 1; i <= N; i++) {
        leaders.insert(dsu.find(i));
    }

    int components = leaders.size();
    cout << modpow(26, components) << "\n";
}
