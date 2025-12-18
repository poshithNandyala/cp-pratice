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
        // cout << (k / (n - 1)) * n + ((k % (n - 1)?k % (n - 1):-1)) << endl;
        cout << (k - 1) / (n - 1) * n
            + (k - 1) % (n - 1)
            + 1 << endl;
    }
}
