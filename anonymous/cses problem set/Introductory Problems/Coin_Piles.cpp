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
        int a, b;
        cin >> a >> b;
        int x = 2 * a - b;
        int y = 2 * b - a;
        if(x%3==0 && x/3 >=0 && y%3==0 && y/3 >=0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
