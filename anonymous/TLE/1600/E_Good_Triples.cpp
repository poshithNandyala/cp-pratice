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
        int cnt = 1;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            int mul = 0;
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j <= 9; j++) {
                    for (int k = 0; k <= 9; k++) {
                        if (i + j + k == d) {
                            mul++;
                        }
                    }
                }
            }
            cnt *= mul;
        }
        cout << cnt << endl;
    }
}
