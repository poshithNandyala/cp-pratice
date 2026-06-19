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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> zeros(n + 2), zeroe(n + 2);
        vector<int> ones(n + 2), onee(n + 2);

        for (int i = 1; i <= n; i++) {
            zeros[i] = zeros[i - 1] + (s[i - 1] == '0');
            ones[i] = ones[i - 1] + (s[i - 1] == '1');
        }

        for (int i = n; i >= 1; i--) {
            zeroe[i] = zeroe[i + 1] + (s[i - 1] == '0');
            onee[i] = onee[i + 1] + (s[i - 1] == '1');
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            int nn = r - l + 1;
            if (nn == 1) {
                cout << "NO" << endl;
                continue;
            }
            if ((l != 1 && (s[l - 1] == '0' && zeros[l - 1]) || (s[l - 1] == '1' && ones[l - 1])) || (r != n && (s[r - 1] == '0' && zeroe[r+1]) || (s[r - 1] == '1' && onee[r+1]))) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }

        }
    }
}
