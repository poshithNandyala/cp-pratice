#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<bool> cycle(n + 1, false);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int start = i;
        vector<bool> vis(n + 1, false);
        while (!vis[start]) {
            vis[start] = true;
            start = a[start];
        }
        cout<<start << " ";

    }
}



