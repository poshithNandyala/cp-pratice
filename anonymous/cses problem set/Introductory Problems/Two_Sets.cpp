#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum%2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> val1, val2;
    int target = sum / 2;
    for(int i = n; i >= 1; i--) {
        if(target >= i) {
            val1.push_back(i);
            target -= i;
        } else {
            val2.push_back(i);
        }
    }
    cout<< val1.size() << endl;
    for(auto x: val1) cout << x << " ";
    cout << endl;
    cout<< val2.size() << endl;
    for(auto x: val2) cout << x << " ";
    cout << endl;
}
