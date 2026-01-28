#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<pair<int, int>>  a(n);
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        a[i] = { x,i };
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0;i < n - 1;i++) {
        if (a[i].second > a[i + 1].second) {
            ans++;
        }
    }
    cout << ans << endl;
}
