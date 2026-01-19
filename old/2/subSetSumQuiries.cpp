
#include <bits/stdc++.h>
using namespace std;


#define ll int64_t

#define endl '\n'

const int mx = 1e5 + 10;
int n, q, dp[100][mx], a[100];
bool rec(int i, int sum) {
    if (sum < 0)return 0;
    if (i == -1) {
        if (sum == 0)return 1;
        return 0;
    }
    auto &ans = dp[i][sum];
    if (ans != -1)return ans;
    ans = (rec(i - 1, sum) | rec(i - 1, sum - a[i]));
    return ans;
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    n = arr.size(), q = queries.size();
    for (int i = 0; i < n; i++)a[i] = arr[i];
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> ans;
    for (auto x : queries) {
        if (rec(n - 1, x)) {
            vector<int> t;
            int i = n - 1;
            while (x) {
                if (rec(i-1, x - a[i]))x -= a[i], t.push_back(i);
                i--;
            }
            reverse(t.begin(), t.end());
            ans.push_back(t);
        }
        else {
            ans.push_back({ -1});
        }
    }
    return ans;
}



void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}

