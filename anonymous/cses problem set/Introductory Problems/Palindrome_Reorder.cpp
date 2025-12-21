#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    string s;
    cin >> s;
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    int oddCount = 0;
    char oddChar = '\0';
    for (auto it: freq) {
        if (it.second % 2 != 0) {
            oddCount++;
            oddChar = it.first;
        }
    }
    if (oddCount > 1) {
        cout << "NO SOLUTION" << endl;
    } else {
        string ans;
        for (auto it : freq) {
            if (it.second % 2 == 0) {
                ans += string(it.second / 2, it.first);
            }
        }
        string revAns = ans;
        reverse(revAns.begin(), revAns.end());
        ans = ans + (oddCount == 1 ? string(freq[oddChar], oddChar) : "") + revAns;
        cout << ans << endl;
    }
}
