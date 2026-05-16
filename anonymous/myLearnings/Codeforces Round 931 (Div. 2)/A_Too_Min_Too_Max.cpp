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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mx = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (i == j) continue;
                for (int k = 0;k < n;k++) {
                    if (k == i || k == j)continue;
                    for (int l = 0;l < n;l++) {
                        if (l == i || l == j || l == k)continue;
                        int cur = abs(a[i] - a[j]) + abs(a[j] - a[k]) + abs(a[k] - a[l]) + abs(a[l] - a[i]);
                        mx = max(mx, cur);
                    }
                }
            }
        }
        cout << mx << endl;
    }
}
