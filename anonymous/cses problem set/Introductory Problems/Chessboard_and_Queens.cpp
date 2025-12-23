#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
bool is_Safe(string board[], int r, int c, vector<bool>& col, vector<bool>& ld, vector<bool>& rd) {

    return  !col[c] && !ld[r + c] && !rd[r - c + 7];
}
int rec(string board[], int r, vector<bool>& col, vector<bool>& ld, vector<bool>& rd) {
    if (r == 8) {
        return 1;
    }
    int ans = 0;
    for (int i = 0;i < 8;i++) {
        if (board[r][i] == '.') {
            if (is_Safe(board, r, i, col, ld, rd)) {
                col[i] = true;
                ld[r + i] = true;
                rd[r - i + 7] = true;
                ans += rec(board, r + 1, col, ld, rd);
                col[i] = false;
                ld[r + i] = false;
                rd[r - i + 7] = false;
            }
        }
    }
    return ans;
}
int32_t main() {
    fastio
    string board[8];
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    vector<bool> col(8, 0);
    vector<bool> ld(15, 0);
    vector<bool> rd(15, 0);
    cout << rec(board, 0, col, ld, rd) << endl;
    return 0;
}
