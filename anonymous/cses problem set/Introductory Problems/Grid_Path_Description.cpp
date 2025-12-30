#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

const int N = 7;
string s;
int ans = 0;
vector<vector<int>> vis(N, vector<int>(N, 0));

bool is_valid(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) return false;
    return true;
}

void dfs(int i, int j, int steps) {

    if (steps == 48 || (i == 6 && j == 0)) {
        if (steps == 48 && i == 6 && j == 0) ans++;
        return;
    }

    if (
        ((!is_valid(i - 1, j) || vis[i - 1][j]) &&
         (!is_valid(i + 1, j) || vis[i + 1][j]) &&
          is_valid(i, j - 1) && !vis[i][j - 1] &&
          is_valid(i, j + 1) && !vis[i][j + 1])
        ||
        ((!is_valid(i, j - 1) || vis[i][j - 1]) &&
         (!is_valid(i, j + 1) || vis[i][j + 1]) &&
          is_valid(i - 1, j) && !vis[i - 1][j] &&
          is_valid(i + 1, j) && !vis[i + 1][j])
       ) {
        return;
    }

    vis[i][j] = 1;

    if (s[steps] == '?' || s[steps] == 'L') {
        if (is_valid(i, j - 1) && !vis[i][j - 1]) {
            dfs(i, j - 1, steps + 1);
        }
    }
    if (s[steps] == '?' || s[steps] == 'R') {
        if (is_valid(i, j + 1) && !vis[i][j + 1]) {
            dfs(i, j + 1, steps + 1);
        }
    }
    if (s[steps] == '?' || s[steps] == 'U') {
        if (is_valid(i - 1, j) && !vis[i - 1][j]) {
            dfs(i - 1, j, steps + 1);
        }
    }
    if (s[steps] == '?' || s[steps] == 'D') {
        if (is_valid(i + 1, j) && !vis[i + 1][j]) {
            dfs(i + 1, j, steps + 1);
        }
    }

    vis[i][j] = 0;
}

int32_t main() {
    fastio
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}
