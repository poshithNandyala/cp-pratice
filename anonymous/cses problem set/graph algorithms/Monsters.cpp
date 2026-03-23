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
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    // Step 1: Monster BFS
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    int ai = 0, aj = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'M') {
                q.push({i, j});
                dist[i][j] = 0;
            }
            if (s[i][j] == 'A') {
                ai = i;
                aj = j;
            }
        }
    }

    while (!q.empty()) {
        auto it = q.front(); q.pop();
        int x = it.first, y = it.second;

        for (auto d : dir) {
            int nx = x + d.first;
            int ny = y + d.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                s[nx][ny] == '.' && dist[nx][ny] == 1e9) {

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // Step 2: Player BFS
    queue<pair<int,int>> q2;
    vector<vector<int>> dist1(n, vector<int>(m, -1));

    q2.push({ai, aj});
    dist1[ai][aj] = 0;

    int outi = -1, outj = -1;

    // If already on boundary
    if (ai == 0 || aj == 0 || ai == n-1 || aj == m-1) {
        cout << "YES\n0\n\n";
        return 0;
    }

    while (!q2.empty()) {
        auto it = q2.front(); q2.pop();
        int x = it.first, y = it.second;

        for (auto d : dir) {
            int nx = x + d.first;
            int ny = y + d.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                s[nx][ny] == '.' &&
                dist1[nx][ny] == -1 &&
                dist1[x][y] + 1 < dist[nx][ny]) {

                dist1[nx][ny] = dist1[x][y] + 1;
                q2.push({nx, ny});

                if (nx == 0 || ny == 0 || nx == n-1 || ny == m-1) {
                    outi = nx;
                    outj = ny;
                    break;
                }
            }
        }
        if (outi != -1) break;
    }

    // Step 3: Path reconstruction
    if (outi != -1) {
        cout << "YES" << endl;
        cout << dist1[outi][outj] << endl;

        int i = outi, j = outj;
        vector<char> ans;

        while (dist1[i][j] != 0) {
            for (auto d : dir) {
                int ni = i + d.first;
                int nj = j + d.second;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    dist1[ni][nj] == dist1[i][j] - 1) {

                    if (d.first == -1) ans.push_back('D');
                    else if (d.first == 1) ans.push_back('U');
                    else if (d.second == 1) ans.push_back('L');
                    else ans.push_back('R');

                    i = ni;
                    j = nj;
                    break;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        for (char c : ans) cout << c;
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}