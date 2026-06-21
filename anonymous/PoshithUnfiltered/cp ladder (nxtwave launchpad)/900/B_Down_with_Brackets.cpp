#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

bool isBalanced(const string &s) {
    vector<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return false;
            }
            char top = st.back();
            st.pop_back();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int32_t main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        string ss = s.substr(1, n - 2);

        if (!isBalanced(ss)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
