#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    int ans = 0;
    while(n>0){
        n /= 5;
        ans += n;
    }
    cout << ans << endl;
    return 0;
}
