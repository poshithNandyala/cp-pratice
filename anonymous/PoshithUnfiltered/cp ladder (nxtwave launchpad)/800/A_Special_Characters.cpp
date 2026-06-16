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
         string s;
            for (int i = 0; i < 50; i++) {
                s += "AABB";
            }
        cin >> n;
        if (n % 2) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << s.substr(0, n)<<endl;
        }
    }
}
