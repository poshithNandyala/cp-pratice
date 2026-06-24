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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int up = 0, down = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') up++;
            else down++;
        }
        int first = up / 2;
        int second = up / 2 + up % 2;
        cout<<first*second*down<<endl;
    }
}
