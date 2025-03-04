#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

int32_t main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = v[i] - i; j <= n; j += v[i]){
                if(j >= 1 && i < j && v[i] * v[j] == i + j){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}