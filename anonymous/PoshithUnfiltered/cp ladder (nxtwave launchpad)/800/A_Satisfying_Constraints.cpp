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
        int st = INT_MIN, en = INT_MAX;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (a == 1) {
                st = max(st, b);
            }
            if (a == 2) {
                en = min(en, b);
            }
            if (a == 3) {
                ans.push_back(b);
            }
        }
        int h = 0;
        for (auto i : ans) {
            if (i >= st && i <= en) h++;
        }
        cout << max(0LL, en - st + 1 - h) << endl;
    }
}
