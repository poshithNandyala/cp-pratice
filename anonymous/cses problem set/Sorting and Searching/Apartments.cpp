#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, ans = 0;
    while(i<n && j<m){
        if (b[j] > (a[i] + k)) {
            i++;
        }else if (b[j] < (a[i] - k)) {
            j++;
        }else{
            ans++;
            i++;
            j++;
        }   
        
    }
    cout<<ans<<endl;
}
