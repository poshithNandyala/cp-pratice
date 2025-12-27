#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string notallowed = "";
            notallowed.append(string(1, grid[i][j]));

            if (i - 1 >= 0) {
                notallowed.append(string(1, grid[i - 1][j]));
            }
            if (j - 1 >= 0) {
                notallowed.append(string(1, grid[i][j - 1]));
            }
            string allowed;
            for (char c = 'A';c <= 'D';c++) {
                if (notallowed.find(c) == string::npos) {
                    allowed.push_back(c);
                }
            }
            grid[i][j] = allowed[0];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
