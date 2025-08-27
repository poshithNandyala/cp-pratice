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
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        if (*max_element(a.begin(), a.end()) == 0) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        vector<int> pos, neg;
        for (int x : a) {
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }
        sort(pos.rbegin(), pos.rend());
        sort(neg.rbegin(), neg.rend());
        int prefix_sum = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (prefix_sum <= 0 && !pos.empty()) {
                ans.push_back(pos.back());
                prefix_sum += pos.back();
                pos.pop_back();
            } else if (!neg.empty()) {
                ans.push_back(neg.back());
                prefix_sum += neg.back();
                neg.pop_back();
            } else if (!pos.empty()) {
                ans.push_back(pos.back());
                prefix_sum += pos.back();
                pos.pop_back();
            }
        }
        for (int x : ans) cout << x << ' ';
        cout << endl;
    }
}
