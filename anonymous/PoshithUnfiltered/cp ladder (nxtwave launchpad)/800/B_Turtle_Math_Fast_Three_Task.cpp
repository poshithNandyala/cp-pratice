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
        vector<int> a(n);
        int sum = 0;
        vector<int> b(3,0);
        for (int i = 0;i < n;i++) {
            cin >> a[i];
            a[i] = a[i] % 3;
            sum += a[i];
            b[a[i]]++;
        }
        if (sum % 3 == 0) cout << 0 << endl;
        else if (sum % 3 == 1 && b[1] > 0) cout << 1 << endl;
        else if (sum % 3 == 2 ) cout << 1 << endl;
        else cout << 2 << endl;
    }
}
