#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
int mod = 1e9 + 7;



int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}
int32_t main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout<< ((fact(n)*n)%mod *(n-1))%mod << endl;
    }
}
