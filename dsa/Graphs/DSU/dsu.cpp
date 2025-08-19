#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int par[N], size[N];

void make_set(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        size[i] = 1;
    }
}

// Path Compression
int find_leader(int x) {
    if (par[x] != x)
        par[x] = find_leader(par[x]);
    return par[x];
}

// Union by Size
void merge(int x, int y) {
    x = find_leader(x);
    y = find_leader(y);
    if (x == y) return;

    if (size[x] < size[y])
        swap(x, y);

    par[y] = x;
    size[x] += size[y];
}

// Count components
int count_components(int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] == i) cnt++;  // node is its own leader
    }
    return cnt;
}

int main() {
    int n = 5;  // number of nodes
    make_set(n);

    // Example edges
    merge(0, 1);
    merge(1, 2);
    merge(3, 4);

    cout << "Number of components: " << count_components(n) << endl;
    // Output: 2 (component1: 0,1,2; component2: 3,4)

    merge(2, 3);  // merge all nodes into one component
    cout << "Number of components after merge: " << count_components(n) << endl;
    // Output: 1

    return 0;
}
