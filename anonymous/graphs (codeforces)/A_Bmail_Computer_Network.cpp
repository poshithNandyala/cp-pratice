#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2;i <= n;i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    vector<int> par(n + 1, -1);
    queue<int> q;
    q.push(1);
    par[1] = -1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            par[it] = node;
            q.push(it);
        }
    }
    vector<int> ans;
    int curr = n;
    while (curr != -1) {
        ans.push_back(curr);
        curr = par[curr];
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
}
