#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({ x, -1 });
        a.push_back({ y, 1 });
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for (auto it : a) {
        cnt += it.second;
        if (cnt < -2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
