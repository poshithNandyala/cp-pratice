#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> vis(n + 1, 0), ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int j = i;
            if (!vis[j]) {
                int c = 0;
                while (!vis[j]) {
                    vis[j] = 1;
                    j = a[j];
                    c++;
                }
                j = i;
                while (vis[j]) {
                    ans[j] = c;
                    vis[j] = 0;
                    j = a[j];

                }
                while (!vis[j]) {
                    vis[j] = 1;
                    j = a[j];
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
