#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
        int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1, ans = 0;
    while(i<=j){
        if(a[i] + a[j] <= x){
            i++;
            j--;
            ans++;
        }
        else{
            j--;
            ans++;
        }
    }
    cout << ans << endl;
}
