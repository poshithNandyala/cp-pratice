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
        vector<int> a(2 * n);
        int sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += a[i];
        }
        cout << a[(2 * n) - 1] << " ";
        for (int i = 0;i < n - 1;i++) {
            cout << a[i] << " " << a[i + n] << " ";
        }
        cout << sum - (ans * 2) << " "<<a[n - 1];
        
        cout << endl;
    }
}
