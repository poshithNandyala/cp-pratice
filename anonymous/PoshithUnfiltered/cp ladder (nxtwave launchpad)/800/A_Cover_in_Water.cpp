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
        int em = 0;
        vector<int> a;
        for(int i=0;i<n;i++) {
            if (s[i] == '.') {
                em++;
            }
            else if(em>0) {
                a.push_back(em);
                em = 0;
            }
        }
        if(em>0) a.push_back(em);
        sort(a.begin(), a.end());
        if (a.size() && a.back() >= 3) {
            cout << 2 << endl;
        }
        else {
            cout << accumulate(a.begin(), a.end(), 0) << endl;
        }
    }
}
