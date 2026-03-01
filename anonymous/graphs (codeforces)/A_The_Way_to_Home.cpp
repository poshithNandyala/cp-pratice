#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    int t=1;
    // cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        string s;
        cin >> s;
        int pos = 0, ans = 0;
        while(pos < n-1) {
            int pos2 = min(pos + d, n-1);
            while(pos2 > pos && s[pos2] == '0') pos2--;
            if(pos2 == pos) {
                ans = -1;
                break;
            }
            pos = pos2;
            ans++;
        }
        cout << ans << endl;
    }
}
