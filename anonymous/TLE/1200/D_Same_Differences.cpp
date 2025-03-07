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
        map<ll, ll> mp;
        for(ll i = 0; i < n; i++){
            mp[a[i] - i]++;
        }
        ll ans = 0;
        for(auto i : mp){
            ans += ((i.second * (i.second - 1)) / 2);
        }
        cout << ans << endl;
    }
}