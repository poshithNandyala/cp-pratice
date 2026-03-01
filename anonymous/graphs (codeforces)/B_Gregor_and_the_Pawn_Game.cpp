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
        string s, t;
        cin >> s >> t;
        int ans = 0;
        for (int i = 0;i < n;i++) {
            if (t[i] == '1') {
                if (i - 1 >= 0  && s[i - 1] == '1') {
                    s[i - 1] = '2';
                    ans++;
                }
                else if (s[i] == '0') {
                    s[i] = '2';
                    ans++;
                }
                else {
                    if (i + 1 < n) {
                        if (s[i + 1] == '1') {
                            s[i + 1] = '2';
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
