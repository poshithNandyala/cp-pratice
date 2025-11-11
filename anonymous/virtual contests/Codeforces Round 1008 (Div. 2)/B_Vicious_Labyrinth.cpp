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
        int n, x;
        cin >> n >> x;
        int v = n;
        if ((x % 2)==0) {
            v -= 1;
        }
        for (int i = 1; i <= n - 2; i++) {
            cout << v << " ";
        }
        cout << n << " " << n - 1 << endl;

    }
}
