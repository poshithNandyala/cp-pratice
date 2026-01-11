#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        if(it==s.begin()){
            cout << -1 << endl;
            continue;
        }
        it--;
        cout << *it << endl;
        s.erase(it);
    }
    return 0;
}
