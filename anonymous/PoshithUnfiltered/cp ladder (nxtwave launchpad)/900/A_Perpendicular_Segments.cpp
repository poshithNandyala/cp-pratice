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
        int x, y, k;
        cin >> x >> y >> k;
        int mi = min(x, y);
        cout << 0 << " " << 0 << " " << mi << " " << mi << endl;
        cout << 0 << " " << mi << " " << mi << " " << 0 << endl;
    }
}
