#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0;i < n;i++) cin >> a[i];
        vector<int> b;
        int c = 1;
        for (int i = 1;i < n;i++) {
            if (a[i] == a[i - 1]) {
                c++;
            }
            else {
                b.push_back(c);
                c = 1;
            }
            if (i == n - 1) b.push_back(c);
        }
        // for(auto item : b){
        //     cout << item << " ";
        // }
        // cout << "\n";

        int ans = 0;
        for (int i = 1;i < b.size();i++) {
            ans = max(ans, min(b[i], b[i - 1]));
        }
        cout << ans * 2 << endl;
    }
}
