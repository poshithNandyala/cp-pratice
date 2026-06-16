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
        string b, a;
        cin >> b >> a;
        int ans = 0;
        for(int i=0;i<n;i++) {
            if (a[i] == '1' && i > 0 && b[i - 1] == '1') {
                b[i-1] = '0';
                ans++;
            }
            else if (a[i] == '1' && b[i] == '0') {
                ans++;
            }
            else if (a[i] == '1' && i + 1 < n && b[i+1] == '1') {
                b[i+1] = '2';
                ans++;
            }
        }
        cout << ans << endl;
    }
}
