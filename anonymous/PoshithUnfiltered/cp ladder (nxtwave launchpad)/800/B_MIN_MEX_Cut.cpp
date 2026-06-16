#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio

    int tc;
    cin >> tc;

    while (tc--) {
        string s;
        cin >> s;

        string ans;
        ans.push_back(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                ans.push_back(s[i]);
            }
        }

        cout << min((long long)count(ans.begin(), ans.end(), '0'), 2LL) << endl;
    }
}