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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int mx = -1, c = 0,v=1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                c++;
                a[i] = v++;
            }
            else {
                c = 0;
            }
            mx = max(mx, c);
        }
        if (mx >= k) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0;i < n;i++) {
            if (s[i] == '0') {
                a[i] = v++;
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
