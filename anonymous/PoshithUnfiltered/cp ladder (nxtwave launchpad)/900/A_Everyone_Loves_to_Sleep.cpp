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
        int n,h,m;
        cin >> n >> h >> m;
        int ansh = 24, ansm = 60;
        for(int i = 0; i < n; i++) {
            int a,b;
            cin >> a >> b;
            int hh = a - h;
            int mm = b - m;
            if (hh < 0) {
                hh += 24;
            }
            if (mm< 0) {
                hh--;
                if(hh < 0) {
                    hh += 24;
                }
                mm += 60;
            }
            if((ansh*60 + ansm )> (hh*60 + mm)) {
                ansh = hh;
                ansm = mm;
            }
            // cout<<ansh<<" "<<ansm<<endl;
        }
        cout << ansh << " " << ansm << endl;
        // cout << endl;
    }
}
