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
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    int ans = 0, v = a[0];
    for (int i = 1;i < n;i++) {
        if (a[i] < v) {
            ans += (v - a[i]);
        }
        else {
            v = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
