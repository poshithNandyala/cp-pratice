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
        int n, a, b;
        cin >> n >> a >> b;
        if (b > a && n%2==b%2) cout<<"YES"<<endl;
        else if (n % 2 == a % 2 && a % 2 == b % 2) cout << "YES" << endl;
        else cout<<"NO"<<endl;
    }
}
