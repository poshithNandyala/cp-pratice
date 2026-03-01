#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'W') {
                if (i - 1 >= 0 && s[i - 1][j] == 'S') {
                    cout << "No" << endl;
                    return 0;
                }
                if (i + 1 < n && s[i + 1][j] == 'S') {
                    cout << "No" << endl;
                    return 0;
                }
                if (j - 1 >= 0 && s[i][j - 1] == 'S') {
                    cout << "No" << endl;
                    return 0;
                }
                if (j + 1 < m && s[i][j + 1] == 'S') {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                s[i][j] = 'D';
            }
        }
        cout << s[i] << endl;
    }
}
