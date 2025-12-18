#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    cout << n << " ";
    while (n != 1) {
        if (n % 2) {
            n = n * 3 + 1;
        }
        else {
            n /= 2;
        }
        cout << n << " ";
    }
    cout << endl;
    
}
