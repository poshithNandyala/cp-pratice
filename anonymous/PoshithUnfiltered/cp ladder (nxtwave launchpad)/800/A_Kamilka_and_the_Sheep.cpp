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
        int mi = INT_MAX, ma = INT_MIN, n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mi = min(mi, x);
            ma = max(ma, x);
        }
        cout << ma - mi << endl;
    }
}
