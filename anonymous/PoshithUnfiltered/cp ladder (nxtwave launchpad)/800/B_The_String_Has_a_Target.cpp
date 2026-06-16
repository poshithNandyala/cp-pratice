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
        char mn = *min_element(s.begin(), s.end());
        for(int i=n-1;i>=0;i--) {
            if(s[i] == mn) {
                cout << mn  ;
                cout << s.substr(0, i);
                cout << s.substr(i + 1) << endl;
                break;
            }
        }
    }
}
