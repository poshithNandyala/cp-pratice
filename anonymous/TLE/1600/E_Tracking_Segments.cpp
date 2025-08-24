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
        int m, n;
        cin >> n >> m;
        vector<pair<int, int>> seg(m);
        for (int i = 0; i < m; i++) {
            cin >> seg[i].first >> seg[i].second;
        }
        int q;
        cin >> q;
        vector<int> que(q);
        for (int i = 0; i < q; i++) {
            cin >> que[i];
        }
        int lo = 1, hi = q, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<int> a(n + 1);
            for (int i = 0; i < mid; i++) {
                a[que[i]]++;
            }
            for (int i = 1; i <= n; i++) {
                a[i] += a[i - 1];
            }
            bool ok = false;
            for (int i = 0; i < m; i++) {
                int ones = a[seg[i].second] - a[seg[i].first - 1];
                int len = seg[i].second - seg[i].first + 1;
                if (ones > len / 2) {
                    ok = true;
                    break;
                }

            }
            if (ok) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
