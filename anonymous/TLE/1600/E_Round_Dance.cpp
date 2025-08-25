 #include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<set<int>> g(n);
        for (int i = 0; i < n; i++) {
            g[i].insert(a[i]);
            g[a[i]].insert(i);
        }
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = g[i].size();
        }
        vector<bool> vis(n, false);
        int c = 0;
        int nc = 0;
    for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = true;
                vector<int> component = { i };
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : g[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                            component.push_back(v);
                        }
                    }
                }
                bool flag = false;
                for (int u : component) {
                    if (d[u] == 1) {
                        flag = true;
                        break;
                    }
                }

                if (flag) {
                    nc++;
                } else {
                    c++;
                }
            }
        }

        cout << c + min(nc, 1LL) << " " << c + nc << endl;
    }

    return 0;
}
