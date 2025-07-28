#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio

        int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    map<int, int> mp;
    bool f = false;
    int ans = 0;
    for (auto& i : v) {
        cin >> i.first >> i.second;
        mp[i.first]++;
        mp[i.second]++;
        if (mp[i.first] > 2) {
            f = true;
            ans = i.first;
        }
        if (mp[i.second] > 2) {
            f = true;
            ans = i.second;
        }
    }
    if (!f) {
        for (int i = 0;i <= (n - 2);i++) {
            cout << i << endl;
        }
    }
    else {
        int c = 0;
        int i = n - 2;
        int k = 3;
        while (c <= (n - 2)) {
            if ((v[c].first == ans || v[c].second == ans) && k) {
                cout << --k << endl;
            }
            else {
                cout << i << endl;
                i--;
            }
            c++;

        }
    }
    return 0;
}
