#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int fact(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

int32_t main() {
    fastio

        string s;
    cin >> s;
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    string ans;
    int ans1 = fact(s.size());
    ans.reserve(s.size());
    for (auto& p : freq) {
        ans.append(p.second, p.first);
        ans1 /= fact(p.second);
    }
    cout << ans1 << endl;
    do {
        cout << ans << endl;
    } while (next_permutation(ans.begin(), ans.end()));
}
