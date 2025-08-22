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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int lo = 0, hi = *max_element(a.begin(), a.end()) + k, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            bool good = false;
            for (int i = 0; i < n; i++) {
                vector<int> min_needed(n);
                min_needed[i] = mid;
                int used = 0;
                for (int j = i; j < n; j++) {
                    if (min_needed[j] <= a[j]) break;
                    if (j + 1 >= n) {
                        used = k + 1; 
                        break;
                    }
                    used += (min_needed[j] - a[j]);
                    min_needed[j + 1] = max(0LL, min_needed[j] - 1);
                }
                if (used <= k) good = true;
            }
            if (good) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans << endl;
    }
}
