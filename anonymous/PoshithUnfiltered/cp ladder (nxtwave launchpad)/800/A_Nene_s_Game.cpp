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
        int k, q;
        cin >> k >> q;
        int mi = INT_MAX;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            mi = min(mi, x);
        }
        while (q--) {
            int n;
            cin >> n;
            cout << min(mi - 1, n) << " ";
        }
        cout << endl;
    }
}
