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
        int x, y;
        cin >> x >> y;
        if (y >= x) {
            if (y % 2) {
                cout << y * y - x + 1 << endl;
            }
            else {
                cout << (y-1)*(y-1) + x << endl;
            }
        }
        else {
            if (x % 2) {
                cout << (x-1)*(x-1) + y << endl;
            }
            else {
                cout << x * x - y + 1 << endl;
            }
        }
    }
}
