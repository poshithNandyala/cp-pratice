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
        ll odd=0, even=0;
        vector<ll> e,o;
        for(ll i=0; i<n; i++) {
            cin >> a[i];
            if(a[i]%2==0) even++, e.push_back(a[i]);
            else odd++, o.push_back(a[i]);
        }
        ll i = 0, j = 0;
        vector<ll> ne;
        while (i < e.size() && j < o.size())
        {
            ne.push_back(e[i]);
            i++;
            ne.push_back(o[j]);
            j++;
        }
        while (i < e.size())
        {
            ne.push_back(e[i]);
            i++;
        }
        while (j < o.size())
        {
            ne.push_back(o[j]);
            j++;
        }
        ll ans = 0,s=0;
        for(ll i=0; i<ne.size(); i++){
            s+=ne[i];
            if(s%2==0){
                ans++;
                s = 1;
            } 

        }
        cout << ans << endl;
    }
}