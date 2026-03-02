#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        if (bx == cx && by == cy) {
            cout << "YES" << endl;
            continue;
        }
        queue<pair<int, int>> q;
        q.push({ bx, by });
        vector<pair<int, int>> moves = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1},
            { 1, 1 },
            { -1, 1 },
            { 1, -1 },
            { -1, -1 }
        };
        unordered_map<int, unordered_map<int, bool>> visited;
        visited[bx][by] = true;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for (auto m : moves) {
                int dx = m.first;
                int dy = m.second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && (nx != ax) && (ny != ay) && ((ny - nx) != (ay - ax)) && ((nx + ny) != (ax + ay)) && !visited[nx][ny]) {
                    if (nx == cx && ny == cy) {
                        cout << "YES" << endl;
                        goto end;
                    }
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                }
            }
        }
        cout << "NO" << endl;
        end:;
    }
}
