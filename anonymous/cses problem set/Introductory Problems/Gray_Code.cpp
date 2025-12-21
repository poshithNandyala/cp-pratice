#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

vector<string> grayCode(int n) {
    vector<string> ans;
    if (n == 0) {
        ans.push_back("0");
        return ans;
    }
    if (n == 1) {
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    vector<string> prev = grayCode(n - 1);
    for (int i=0; i<prev.size(); i++) {
        ans.push_back("0" + prev[i]);
    }
    for (int i = prev.size() - 1; i >= 0; i--) {
        ans.push_back("1" + prev[i]);
    }
    return ans;
}
int32_t main() {
    fastio
    int n;
    cin >> n;
    vector<string> ans = grayCode(n);
    for (string s : ans) {
        cout << s << endl;
    }
    return 0;
}
