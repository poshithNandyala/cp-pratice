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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int y = a[n - 1];
        int x = a[0] + a[1];
        if(y>x) {
            cout << "YES" << endl;
            continue;
        }
        int i = 2, j = n - 2;
        while (i < j) {
            y+=a[j--];
            x += a[i++];
            if(y>x) {
                cout << "YES" << endl;
                break;
            }
        }
        if (x >=y) {
            cout << "NO" << endl;
        }
    }
}
