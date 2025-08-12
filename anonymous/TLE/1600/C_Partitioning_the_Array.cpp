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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int gcd = 0;
                int k = i;
                for (int j = k + 1; j <= n; j++) {
                    gcd = __gcd(gcd, abs(a[j] - a[j - k]));
                }
                ans += (gcd != 1);
                if (k != n / k) {
                    gcd = 0;
                    k = n / i;
                    for (int j = k + 1; j <= n; j++) {
                        gcd = __gcd(gcd, abs(a[j] - a[j - k]));
                    }
                    ans += (gcd != 1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
