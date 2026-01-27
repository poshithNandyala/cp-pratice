#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0;i < n;i++) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int mx = 0, curr = 0;
    int i = 0, j = 0;
    while (j < n && i < n) {
        while (a[i] <= b[j] && i < n) {
            curr++;
            i++;
        }
        mx = max(mx, curr);
        j++;
        curr--;
    }
    cout << mx << endl;
}
