#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    cout.setf(std::ios::fixed); 
    cout << setprecision(10);
    while (T--) {
        int n; cin >> n;
        vector<long long> x(n), t(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> t[i];

        long double L = 1e30L, R = -1e30L;
        for (int i = 0; i < n; ++i) {
            L = min(L, (long double)x[i] - (long double)t[i]);
            R = max(R, (long double)x[i] + (long double)t[i]);
        }
        long double x0 = (L + R) / 2.0L;
        cout << x0 << "\n";
    }
    return 0;
}

