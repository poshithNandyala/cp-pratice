#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> last; // last position of each song
    int left = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {

        // If duplicate appears inside current window
        if (last.count(a[i])) {
            left = max(left, last[a[i]] + 1);
        }

        // Update answer
        ans = max(ans, i - left + 1);

        // Update last position
        last[a[i]] = i;
    }

    cout << ans << "\n";
    return 0;
}
