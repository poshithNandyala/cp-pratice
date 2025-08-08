#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = abs(a[i] - x);
        pq.push(a[i]);
    }
    int k = k1 + k2;
    bool ans = false;
    while (k) {
        int x = pq.top();
        if (!x) {
            ans = true;
            break;
        }
        pq.pop();
        pq.push(x - 1);
        k--;
    }
    if (ans) {
        cout << k % 2 << endl;
    }
    else {
        int anss = 0;
        while (!pq.empty()) {
            anss += (pq.top()*pq.top());
            pq.pop();
        }
        cout << anss << endl;
    }
}

