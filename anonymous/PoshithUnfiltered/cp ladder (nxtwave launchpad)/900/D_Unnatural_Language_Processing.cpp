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
        string t(n, '0');
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i]=='e') {
                t[i] = 'v';
            }
            else{
                t[i] = 'c';
            }
        }
        string ans;
        int i = n - 1;
        while (i >= 0) {
            if (i >= 2 && t[i] == 'c' && t[i - 1] == 'v' && t[i - 2] == 'c') {
                ans.push_back(s[i]);
                ans.push_back(s[i - 1]);
                ans.push_back(s[i - 2]);
                i -= 3;
            }
            else {
                ans.push_back(s[i]);
                ans.push_back(s[i - 1]);
                i -= 2;
            }
            if(i<0) break;
            ans.push_back('.');
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}
