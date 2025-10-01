#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);


int ans = 0;
void rec(string& a, string& b, int n, int i, map<char, int>& mp, map<char, int>::iterator it, int k) {
    if (i == k) {
        int temp = 0, c = 0;
        for (int j = 0;j < n;j++) {
            if (a[j] == b[j] || mp[a[j]] == -1) {
                c++;
            }
            else {
                temp += (c * (c + 1)) / 2;
                c = 0;
            }
        }
        temp += (c * (c + 1)) / 2;
        ans = max(ans, temp);
        return;
    }
    if (it == mp.end()) {
        return;
    }
    auto nextIt = it;
    ++nextIt;
    rec(a, b, n, i, mp, nextIt, k);
    mp[it->first] = -1;
    rec(a, b, n, i + 1, mp, nextIt, k);
    mp[it->first] = 1;

}
int32_t main() {
    fastio
        int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        map<char, int> mp;
        for (int i = 0;i < n;i++) {
            if (a[i] != b[i]) {
                mp[a[i]]++;
            }
        }
        if (mp.size() <= k) {
            cout << n * (n + 1) / 2 << endl;
            continue;
        }
        auto it = mp.begin();
        rec(a, b, n, 0, mp, it, k);
        cout << ans << endl;
        ans = 0;
    }
}