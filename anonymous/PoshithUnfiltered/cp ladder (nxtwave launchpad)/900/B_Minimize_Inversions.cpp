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
        vector<pair<int, int>> ab(n);
        for (int i = 0;i < n;i++) {
            cin >> ab[i].first;
        }
        for (int i = 0;i < n;i++) {
            cin >> ab[i].second;
        }
        sort(ab.begin(), ab.end());
        for (int i = 0;i < n;i++) {
            cout << ab[i].first << " ";
        }
        cout << endl;
        for (int i = 0;i < n;i++) {
            cout << ab[i].second << " ";
        }
        cout << endl;
    }
}
