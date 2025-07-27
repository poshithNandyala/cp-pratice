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
        string s;
        cin >> s;

        vector<map<char, int>> mp((k + 1) / 2);

        for (int i = 0; i < n; i++) {
            int pos = i % k;
            int group = min(pos, k - 1 - pos);
            mp[group][s[i]]++;
        }

        int anss = 0;
        for (int i = 0; i < ((k + 1) / 2); i++) {
            int max_freq = 0;
            for (auto it = mp[i].begin(); it != mp[i].end(); ++it) {
                max_freq = max(max_freq, it->second);
            }

            if (k % 2 && i == ((k + 1) / 2) - 1) {
                anss += ((n / k) - max_freq);
            } else {
                anss += ((n / k) * 2 - max_freq);
            }
        }

        cout << anss << endl;
    }
}
