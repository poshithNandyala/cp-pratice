#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0;i < n;i++) cin >> a[i].second>>a[i].first;
    sort(a.begin(), a.end());
    int ans = 0;
    int end = 0;
    for(int i=0;i<n;i++){
        if(a[i].second>=end){
            ans++;
            end = a[i].first;
        }
    }
    cout<<ans<<endl;
}
