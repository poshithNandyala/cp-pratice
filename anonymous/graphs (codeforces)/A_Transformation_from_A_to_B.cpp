#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    int t=1;
    // cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        unordered_map<int, int> p;
        queue<int> q;
        q.push(a);
        p[a] = 0;
        bool ans = false;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == b) {
                ans = true;
                break;
            }
            if ( curr * 2 <= b && p[curr * 2] == 0) {
                q.push(curr * 2);
                p[curr * 2] = curr;
            }
            if (curr * 10 + 1 <= b && p[curr * 10 + 1] == 0) {
                q.push(curr * 10 + 1);
                p[curr * 10 + 1] = curr;
            }
        }
        if (ans) {
            vector<int> path;
            int curr = b;
            while (curr != 0) {
                path.push_back(curr);
                curr = p[curr];
            }
            reverse(path.begin(), path.end());
            cout << "YES" << endl;
            cout << path.size() << endl;
            for (int x : path) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
