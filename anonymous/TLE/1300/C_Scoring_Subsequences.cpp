#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

const int N = 1e5 + 10;

int main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[N];
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << 1 << ' ';
        int cnt = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i - cnt] > cnt) cnt++;
            cout << cnt << ' ';
        }
        cout << endl;
    }
    return 0;
}