#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int t=1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
            bool ans = true;
        for (int i = 1;i <= n;i++) {
            int first = i;
            int second = a[first];
            int third = a[second];
            if (a[third] == first && first != second && second != third && third != first) {
                cout << "YES" << endl;
                ans = false;
                break;
            }

        }
        if (ans) cout << "NO" << endl;
    }
}
