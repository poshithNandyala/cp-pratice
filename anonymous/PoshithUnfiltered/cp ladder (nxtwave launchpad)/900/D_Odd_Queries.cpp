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
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1, 0);
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        vector<int> sum(n + 1, 0);
        for (int i = 1;i <= n;i++) {
             sum[i] = sum[i - 1] + a[i];
        }
        while (q--) {
            int l, r,k;
            cin >> l >> r >> k;
            int tot = sum[r ] - sum[l - 1];
            if (sum[n] % 2==(tot%2 == ((r-l+1)*k)%2)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}
