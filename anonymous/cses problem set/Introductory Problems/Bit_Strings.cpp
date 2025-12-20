#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    int n;
    cin >> n;
    int ans = 1;
    int mod = 1e9 + 7;
    for(int i = 0; i < n; i++) {
        ans = (ans * 2) % mod;
    }
    cout << ans << endl;
}
