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
        int zero = 0;
        for (int i = 0;i < n;i++) {
            if(s[i] == '0') zero++;
        }
        int x = 0;
        for (int i = 0;i < zero;i++) {
            if (s[i] == '0') x++;

        }
        cout << zero - x << endl;
    }
}
