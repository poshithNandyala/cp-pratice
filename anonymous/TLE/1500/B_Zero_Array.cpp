#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio

        int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0,mx=-1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
        mx = max(mx, a[i]);
    }
    if (ans % 2==0 && mx<=ans-mx) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}
