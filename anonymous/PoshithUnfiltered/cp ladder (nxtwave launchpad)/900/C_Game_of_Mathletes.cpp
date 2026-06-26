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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> mp;
        for (int i = 0;i < n;i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        // for(auto item : mp){
        //     cout << item.first << " "<< item.second << " "<<endl;
        // }
        // cout << "\n";
        
        int ans = 0;
        for (auto it : mp) {
            if (it.first <= (k / 2) ) { 
                if (it.first == (k / 2) && (k % 2) == 0) {
                    ans += (it.second / 2);
                }
                else {
                    ans += min(it.second, mp[k - it.first]);
                }
            }
            else {
                break;
            }
        }
        cout << ans << endl;

    }
}
