#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    int x = 0, y = 0;
    grid[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({ x, y });
    while (!q.empty()) {
       pair<int, int> p = q.front();
        q.pop();
        for (auto i : moves) {
            int nx = p.first + i.first;
            int ny = p.second + i.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !(nx == 0 && ny == 0)) {
                grid[nx][ny] = grid[p.first][p.second] + 1;
                q.push({ nx, ny });
            }
        }
    }
    for (auto i : grid) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
