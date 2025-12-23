#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

void rec(vector<int> &a,int sum,int cur,int i,int &ans) {
    if (i == a.size()) {
        ans = min(ans, abs(cur - (sum - cur)));
        return;
    }
    rec(a, sum, cur, i + 1, ans);
    rec(a, sum, cur + a[i], i + 1, ans);
}
int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<int> a(n);
    int sum= 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 1000000000000000;
    rec(a, sum,0, 0, ans);
    cout << ans << endl;
}
