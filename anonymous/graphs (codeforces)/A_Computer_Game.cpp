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
        string a, b;
        cin >> a >> b;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (b[i] == '1' && a[i] == '1') ans = false;
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
