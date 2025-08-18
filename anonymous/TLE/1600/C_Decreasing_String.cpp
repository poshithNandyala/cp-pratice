#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    string ans = "";

    while (t--) {
        string s;
        long long pos;
        cin >> s >> pos;
        int n = s.size();

        vector<int> remove_order;
        stack<int> st;

        string tmp = s;
        tmp.push_back('`');

        for (int i = 0; i < n + 1; i++) {
            while (!st.empty() && s[st.top()] > tmp[i]) {
                remove_order.push_back(st.top());
                st.pop();
            }
            if (i < n) st.push(i);
        }
        while (!st.empty()) {
            remove_order.push_back(st.top());
            st.pop();
        }

        vector<long long> prefix(n);
        prefix[0] = n;
        for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + (n - i);

        int k = int(lower_bound(prefix.begin(), prefix.end(), pos) - prefix.begin()) + 1;
        long long prevSum = (k == 1 ? 0 : prefix[k-2]);

        vector<bool> removed(n, false);
        for (int i = 0; i < k - 1; i++) removed[remove_order[i]] = true;

        string sk = "";
        for (int i = 0; i < n; i++)
            if (!removed[i]) sk.push_back(s[i]);

        ans.push_back(sk[pos - prevSum - 1]); 
    }

    cout << ans << "\n";
    return 0;
}
