#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

int main(){
    fastio
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<ll> c(n);
        map<ll,ll> mp;
        for(ll i = 0; i < n; i++){
            cin >> c[i];
            c[i]=(a[i]-c[i]);
            mp[c[i]]++;
        }
        auto it = mp.end(); 
        it--;
        ll ans = it->second;
        cout << ans << endl;
        for(ll i = 0; i < n; i++){
            if(c[i] == it->first){
                cout << i+1 << " ";
            }
        }
        cout << endl;
    }
}