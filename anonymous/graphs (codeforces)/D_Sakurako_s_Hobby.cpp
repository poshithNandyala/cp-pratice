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
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;
        map<int, int> mp;
        int x = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] > 0) {
                int c = 0;
                int curr = i;
                while (p[curr] > 0) {
                    c += ('1' - s[curr - 1]);
                    // cout << "i: " << i << " curr: " << curr << " c: " << c << " x: " << x << endl;
                    int temp = p[curr];
                    p[curr] = x;
                    curr = temp;     
                }
                mp[x] = c;
                x--;
            }
        }
        // for (auto it : p) {
        //     cout << it << " ";
        // }
        for (int i = 1;i <= n;i++) {
            cout<<mp[p[i]]<<" ";
        }
        cout << endl;
    }
}
