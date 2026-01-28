#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int s = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] > s + 1) {
            break;
        }
        else {
            s += a[i];
        }
    }
    cout << s + 1 << endl;
}
