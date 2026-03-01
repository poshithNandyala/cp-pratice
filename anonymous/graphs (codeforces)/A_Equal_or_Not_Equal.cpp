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
        string s;
        cin >> s;
        if (count(s.begin(), s.end(), 'N') == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}