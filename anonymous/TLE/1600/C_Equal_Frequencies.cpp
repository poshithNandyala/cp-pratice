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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        vector<int> idx(26);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return pos[i].size() > pos[j].size();
        });
        int mx = -1;
        string out;
        for (int k = 1; k <= 26; k++) {
            if (n % k != 0) continue;
            int cnt = n / k;
            int now = 0;
            for (int i = 0; i < k; i++) {
                now += min((int)pos[idx[i]].size(), cnt);
            }
            if (now > mx) {
                mx = now;
                string tmp(n, ' ');
                vector<char> rem;
                for (int i = 0; i < k; i++) {
                    int c = idx[i];
                    for (int j = 0; j < cnt; j++) {
                        if (j < (int)pos[c].size()) {
                            tmp[pos[c][j]] = 'a' + c;
                        } else {
                            rem.push_back('a' + c);
                        }
                    }
                }

                for (int i = 0; i < n; i++) {
                    if (tmp[i] == ' ') {
                        tmp[i] = rem.back();
                        rem.pop_back();
                    }
                }
                out = tmp;
            }
        }
        cout << n - mx << endl;
        cout << out << endl;
    }
    return 0;
}
