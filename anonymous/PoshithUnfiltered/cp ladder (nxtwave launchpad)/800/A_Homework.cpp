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
        int n, m;
        string s, t;
        cin >> n >> s >> m >> t;
        string d;
        cin >> d;
        for (int i = 0;i < m;i++) {
            if (d[i] == 'D') {
                s.push_back(t[i]);
                t[i] = '@';
            }
        }
        reverse(t.begin(), t.end());
        for (int i = 0;i < m;i++) {
            if (t[i] != '@') {
                cout << t[i];
            }
        }
        cout << s << endl;
    }
}
