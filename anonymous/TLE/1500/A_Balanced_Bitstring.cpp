#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string ans = s.substr(0, k);
        bool ok = true;
        for (int i = k;i < n;i++) {
            if (ans[i % k] == '?' && (s[i] == '0' || s[i] == '1')) {
                ans[i % k] = s[i];
            }
            else if ((s[i] == '0' || s[i] == '1') && ans[i % k] != s[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            int one = 0, zero = 0;
            for (int i = 0;i < k;i++) {
                if (ans[i] == '1') one++;
                else if (ans[i] == '0') zero++;
            }
            if (one > k / 2 || zero > k / 2) ok = false;
        }
        if (ok) {
            cout << "YES"  << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}

