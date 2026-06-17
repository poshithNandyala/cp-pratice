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
        int n, m;
        cin >> n >> m;
        int time = 0, po = 0,ans=0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            int diff = a - time;
            if ((diff % 2) == (b != po)) {
                ans += diff;
            }
            else {
                ans += (diff - 1);
            }
            time = a;
            po = b;
        }
        cout << ans  + m-time << endl;
    }
}
