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
        int n = s.size();
        int ans = 1;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                ans = max(ans, i - prev);
                prev = i;
            }
        }
        ans = max(ans, n - prev);
        cout << ans << endl;
    }
}
