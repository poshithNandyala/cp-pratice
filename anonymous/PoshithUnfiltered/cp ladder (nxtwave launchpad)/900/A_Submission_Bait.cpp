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
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        string ans = "NO";
        for(auto it: mp) {
            if(it.second%2) {
                ans = "YES";
                break;
            }
        }
        cout << ans << endl;

    }
}
