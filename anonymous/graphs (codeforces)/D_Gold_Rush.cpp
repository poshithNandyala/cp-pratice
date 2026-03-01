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
        int n, m;
        cin >> n >> m;
        if (m > n) {
            cout << "NO" << endl;
            continue;
        }
        if (n == m) {
            cout << "YES" << endl;
            continue;
        }
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr % 3 == 0) {
                int x = curr / 3;
                int y = 2 * x;
                if (x == m || y == m) {
                    cout << "YES" << endl;
                    goto end;
                }
                q.push(x);
                q.push(y);
            }
        }
        cout << "NO" << endl;
    end:
        ;

    }
}
