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
        string s;
        cin >> s;
        int y=-1,x=-1;
        for (int i = n - 1;i >= 0; i--) {
            if (s[i] == 'B') {
                y = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                x = i;
                break;
            }
        }
        if(y==-1 || x==-1) cout<<0<<endl;
        else cout<<max(0LL,y-x)<<endl;
    }
}
