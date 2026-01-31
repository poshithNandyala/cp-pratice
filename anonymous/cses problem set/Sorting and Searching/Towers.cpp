#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<int> b;
    for (int i = 0;i < n;i++) {
        auto it = upper_bound(b.begin(), b.end(), a[i]);
        if (it == b.end()) {
            b.push_back(a[i]);
        }
        else {
            *it = a[i];
        }
    }
    cout << b.size() << endl;
}
