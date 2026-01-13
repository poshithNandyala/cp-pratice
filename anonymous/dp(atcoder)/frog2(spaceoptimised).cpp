#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio

        int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    deque<int> dp;   // stores dp[i+1] ... dp[i+k]
    dp.push_front(0); // dp[n-1] = 0

    for (int i = n - 2; i >= 0; i--) {
        int best = LLONG_MAX;

        for (int j = 0; j < dp.size(); j++) {
            best = min(best,
                abs(a[i] - a[i + j + 1]) + dp[j]);
        }

        dp.push_front(best);
        if (dp.size() > k) dp.pop_back();
    }

    cout << dp.front() << endl;
    return 0;
}
