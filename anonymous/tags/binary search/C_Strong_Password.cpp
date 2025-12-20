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
        string s;
        cin >> s;
        int m;
        string l, r;
        cin >> m >> l >> r;
        int n = s.size();
        int pos = 0;
        for (int i = 0; i < m; i++) {
            int best = pos;
            for (char j = l[i]; j <= r[i]; j++) {
                int idx = pos;
                while (idx < n && s[idx] != j) idx++;
                best = max(best, idx);
            }
            pos = best + 1;
        }
        cout << (pos > n ? "YES\n" : "NO\n");

    }
    return 0;
}
