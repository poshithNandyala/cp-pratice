#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int total = (i*i) * ((i*i) - 1) / 2;
        int attack = (i - 1) * (i - 2) * 2 * 2;
        cout << total - attack << endl;
    }
}
