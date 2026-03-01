#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, s;
    cin >> n >> s;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
       
        cin >> b[i];
        if (i >= s - 1) {
            if (a[i] == 1 && b[i] == 1) {
                ans = true;
            }
        }
    }
    if (a[0] == 1) {
        if (a[s-1] == 1) {
            cout<<"YES" << endl;
        }
        else if(ans && b[s-1] == 1) {
            cout<<"YES" << endl;
        }
        else {
            cout<<"NO" << endl;
        }
    }
    else {
        cout<<"NO" << endl;
    }
        
}
