#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int msb_pos(int n) {
    if (n == 0) return -1;
    return 64 - __builtin_clzll(n);
}

int32_t main() {
    fastio
    int t;
    cin >> t;
    // vector<int> v(62);
    // int val = 1;
    // for(int i = 0; i <= 61; i++) {
    //     v[i] = val;
    //     val *= 2;
    //     if (i > 0) {
    //         v[i] += v[i - 1];
    //     }
    // }
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1;i < n;i++) {
            if (a[i] < a[i - 1]) {
                ans =max(ans, msb_pos(a[i - 1] - a[i]));
                a[i] = a[i - 1];
            }
        }
        cout << ans << endl;
    }
}
