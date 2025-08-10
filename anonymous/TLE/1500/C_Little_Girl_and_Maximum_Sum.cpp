#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int sum = 0;
    while(k--) {
        int x, y;
        cin >> x >> y;
        x--;
        b[x] += 1;
        b[y] -= 1;
    }
    for (int i = 1; i < n+1; i++) {
        b[i] += b[i-1];
    }
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if(b[i] == 0) break;
        sum += a[i] * b[i];
    }
    cout << sum << endl;
    return 0;
}
