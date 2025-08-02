#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    map<pair<int, int>, int> mp;
    int ans = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) {
            c++;
            continue;
        }
        if (b[i] == 0) {
            mp[{0, 1}]++;
            ans = max(ans, mp[{0, 1}]);
            continue;
        }
        if (a[i] == 0) {
            continue;
        }
        int div = __gcd(a[i], b[i]);
        mp[{a[i] / div, b[i] / div}]++;
        ans = max(ans, mp[{a[i] / div, b[i] / div}]);
    }
    cout << ans + c << endl;
    return 0;

}
