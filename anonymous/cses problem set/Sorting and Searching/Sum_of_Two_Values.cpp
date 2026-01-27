#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, v;
    cin >> n >> v;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i].first = x;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (l < r) {
        int sum=a[l].first + a[r].first;
        if (sum == v) {
            cout<<a[l].second<<" "<<a[r].second<<endl;
            return 0;
        }
        else if(sum<v) l++;
        else r--;
    }
    cout<<"IMPOSSIBLE"<<endl;

}

