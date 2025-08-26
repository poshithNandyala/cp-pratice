#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    const int nmax = 1e6; 
    int d = 1;
    while (d * (d - 1) / 2 < nmax) d++;
    vector<vector<int>> a(d + 5, vector<int>(d + 5, 0));
    vector<int> ans(nmax + 1);
    int curr = 1;
    for (int i = 1; i <= d && curr <= nmax; i++) {
        for (int j = i - 1; j >= 1 && curr <= nmax; j--) {
            int r = j, c = i - j;
            a[r][c] = a[r - 1][c] + a[r][c - 1] - a[r - 1][c - 1] + curr * curr;
            ans[curr] = a[r][c];
            curr++;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}
