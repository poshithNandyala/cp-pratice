#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

int main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        ll a, b, k;
        cin >> a >> b >> k;
        ll ans = (k * (k - 1)) / 2;
        ll aa[k];
        for(int i = 0; i < k; i++){
            cin >> aa[i];
        }
        set<pair<ll, ll>> s;
        for(int i = 0; i < k; i++){
            ll bb;
            cin>> bb;
            s.insert({aa[i], bb});
        }
        map<ll, ll> mpa,mpb;
        for(auto it : s){
            mpa[it.first]++;
            mpb[it.second]++;        
        }
        for(auto it : mpa){
            ans -= (it.second * (it.second - 1)) / 2;
        }
        for(auto it : mpb){
            ans -= (it.second * (it.second - 1)) / 2;
        }
        cout << ans << endl;
    }
}