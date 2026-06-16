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
        char temp = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] == temp) {
                cout << temp;
                temp = s[++i];
            }
        }
        cout << endl;
    }
}
