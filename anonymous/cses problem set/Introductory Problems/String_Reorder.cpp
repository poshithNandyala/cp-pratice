#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
//most frequent cahracter should not be more than floor of (n+1)/2
int32_t main() {
    fastio
        string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26, 0);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
        mx = max(mx, freq[s[i] - 'A']);
    }
    int sum = accumulate(freq.begin(), freq.end(), 0);
    int others = sum - mx;
    if (mx > others + 1) {
        cout << -1 << endl;
    }
    else {
        string ans = "";
        for (int pos = 0; pos < n; pos++) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0 || (!ans.empty() && ans.back() == char('A' + c))) {
                    continue;
                }
                freq[c]--;
                int remaining = n - pos - 1;
                int mx_rem = *max_element(freq.begin(), freq.end());
                if (mx_rem <= (remaining + 1) / 2) {
                    ans += char('A' + c);
                    break;
                }
                else {
                    freq[c]++;
                }
            }
        }
        cout << ans << endl;
    }
}
