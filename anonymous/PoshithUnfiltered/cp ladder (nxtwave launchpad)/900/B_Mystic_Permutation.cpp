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
        int n;
        cin >> n;
        if (n == 1) {
            cin >> n;
            cout << -1<<endl;
            continue;
        }
        vector<int> v(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            pq.push(v[i]);
        }
        // for(auto item : v){
        //     cout << item << " ";
        // }
        // cout << "\n";
        vector<int> ans;
        for (int i = 0; i < n-2; i++) {
            int x = pq.top();
            if (x == v[i]) {
                pq.pop();
                ans.push_back(pq.top());
                pq.pop();
                pq.push(x);
            }
            else {
                ans.push_back(x);
                pq.pop();
            }
        }
        int x = pq.top();
        ans.push_back(pq.top());
        pq.pop();
        int y=pq.top();
        ans.push_back(pq.top());
        pq.pop();

        if (v[n - 2] == x ||  v[n - 1] == y) {
             swap(ans[n - 1], ans[n - 2]);
            
        }
        for (auto item : ans) {
            cout << item << " ";
        }
        cout << endl;

    }
}
