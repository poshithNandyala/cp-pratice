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
        string s, t;
        cin >> s >> t;
        int mi = min(s.size(), t.size());
        int ans = 0;
        int i = 0;
        for (i = 0; i < mi; i++) {
            if (s[i] != t[i]) {
                break;
            }
            ans++;
        }
        if (ans > 0) ans += 1;
        cout << ans + s.size() - i + t.size() - i << endl;
    }
}
