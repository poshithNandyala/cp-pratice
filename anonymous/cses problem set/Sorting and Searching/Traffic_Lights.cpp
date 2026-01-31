#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);


int32_t main() {
    fastio
        int x, n;
    cin >> x >> n;
    vector<int> a(n);
    set<int> s;
    multiset<int> ms;
    s.insert(0);
    s.insert(x);
    ms.insert(x - 0);
    for (int i = 0;i < n;i++) {
        int y;
        cin >> y;

        auto right = s.upper_bound(y);
        auto left = right;
        left--;
        int val = *right - *left;
        auto it = ms.find(val);
        ms.erase(it);
        ms.insert(y - *left);
        ms.insert(*right - y);
        s.insert(y);
        cout << *ms.rbegin() << " ";
    }
}
