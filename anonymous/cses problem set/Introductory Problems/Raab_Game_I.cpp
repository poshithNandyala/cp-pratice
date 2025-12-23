#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

void printfrom1ton(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
}
int32_t main() {
    fastio
        int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a == 0 && b == 0) {
            cout << "YES" << endl;
            printfrom1ton(n);
            printfrom1ton(n);
        }
        else if (a == 0 || b == 0 || a + b > n) {
            cout << "NO" << endl;

        }
        else {
            cout << "YES" << endl;
            printfrom1ton(n);
            for (int i = a + 1;i <= a + b;i++) {
                cout << i << " ";
            }
            for (int i = 1;i <= a;i++) {
                cout << i << " ";
            }
            for (int i = a + b + 1;i <= n;i++) {
                cout << i << " ";
            }
            cout << endl;

        }
    }
}
