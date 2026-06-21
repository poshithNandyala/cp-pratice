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
        vector<int> a(5, 0);
        while (n) {
            for (int i = 0;i < 5;i++) {
                if (n == 0) break;
                a[i]++;
                n--;
            }
        }
        for (int i = 0;i < a[0];i++) cout << 'a';
        for (int i = 0;i < a[1];i++) cout << 'e';
        for (int i = 0;i < a[2];i++) cout << 'i';
        for (int i = 0;i < a[3];i++) cout << 'o';
        for (int i = 0;i < a[4];i++) cout << 'u';
        cout << endl;
    }
}
