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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c -= a;
        d -= b;
        if (a > b) {
            swap(a, b);
        }
        if (c > d) {
            swap(c, d);
        }
        a += 1;
        c += 1;
        b += (a - 1);
        d += (c - 1);
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if (b / a >= 3 || d / c >= 3) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
}
