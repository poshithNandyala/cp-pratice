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
        int x;
        cin >> x;
        int ans = 11;
        while (x > 0) {
            ans = min(ans, x % 10);
            x /= 10;
        }
        cout << ans << endl;
    }
}
