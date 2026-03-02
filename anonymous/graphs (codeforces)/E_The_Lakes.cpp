#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int dfs(int i, int j, vector<vector<int>>& a, vector<vector<bool>>& visited) {
    visited[i][j] = true;
    int ans = a[i][j];
    vector<pair<int, int>> moves = {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 }
    };
    for (auto m : moves) {
        int dx = m.first;
        int dy = m.second;

        int nx = i + dx;
        int ny = j + dy;

        if (nx >= 0 && nx < a.size() && ny >= 0 && ny < a[0].size() && a[nx][ny] && !visited[nx][ny]) {
            ans += dfs(nx, ny, a, visited);
        }
    }
    return ans;
}


int32_t main() {
    fastio
        int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (!visited[i][j] && a[i][j]) {
                    ans = max(ans, dfs(i, j, a, visited));
                }
            }
        }
        cout << ans << endl;
    }
}
