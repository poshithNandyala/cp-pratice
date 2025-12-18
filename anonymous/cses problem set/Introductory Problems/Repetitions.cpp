#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        string s;
    cin >> s;
    int n = s.size();
    int c = 1, ans = 1;
    for (int i = 1;i < n;i++) {
        if (s[i] == s[i - 1]) {
            c++;
        }
        else {
            c = 1;
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
    return 0;
}
