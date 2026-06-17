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
        int ans;
        cin >> ans;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            ans&=x;
        }
        cout << ans << endl;
    }
}
