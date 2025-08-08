#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    int n;
    cin >> n;
    vector<int> a(n);
    int gcd_all = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        gcd_all = __gcd(gcd_all, a[i]);
    }
    if (gcd_all != 1) {
        cout << -1 << endl;
        return 0;
    }

    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ans = 1;
            break;
        }
        int g = a[i];
        for (int j = i + 1; j < n; j++) {
            g = __gcd(g, a[j]);
            if (g == 1) {
                ans = min(ans, j - i);
                break; 
            }
        }
    }

    int cnt_not1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 1) {
            cnt_not1++;
        }
    }

    cout << cnt_not1 + ans - 1 << endl;
}
