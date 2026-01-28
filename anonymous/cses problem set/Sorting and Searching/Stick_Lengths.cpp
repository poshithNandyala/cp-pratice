#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long median = a[n / 2];   // works for both odd and even n
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += llabs(a[i] - median);
    }

    cout << ans << "\n";
    return 0;
}
