#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

const int MOD = 998244353;

int add(int x, int y) {
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y) {
    return x * 1ll * y % MOD;
}

int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x) {
    return binpow(x, MOD - 2);
}

int divide(int x, int y) {
    return mul(x, inv(y));
}

int32_t main() {
    fastio
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n / 6; i++)
        ans = mul(ans, divide(i + n / 6, i));
    for (int i = 0; i < n / 3; i++) {
        vector<int> a(3);
        for (int j = 0; j < 3; j++)
            cin >> a[j];
        int mn = *min_element(a.begin(), a.end());
        int cnt_min = count(a.begin(), a.end(), mn);
        ans = mul(ans, cnt_min);
    }
    cout << ans << endl;
}
