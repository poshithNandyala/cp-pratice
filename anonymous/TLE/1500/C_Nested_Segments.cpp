#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    pair<pair<int, int>, int> seg[n + 1];
    for (int i = 1;i <= n;i++) {
        cin >> seg[i].first.first >> seg[i].first.second;
        seg[i].second = i;
    }
    sort(seg, seg + n + 1);
    for (int i = 2;i <= n;i++) {
        if (seg[i].first.second <= seg[i - 1].first.second) {
            cout << seg[i].second << " " << seg[i - 1].second << endl;
            return 0;
        }
        if (seg[i].first.first == seg[i - 1].first.first) {
            cout << seg[i - 1].second << " " << seg[i].second << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;

}
