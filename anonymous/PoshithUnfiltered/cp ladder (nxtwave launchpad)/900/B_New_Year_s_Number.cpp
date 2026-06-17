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
        int x = n % 2020;
        int y = n / 2020;
        if(x<=y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
