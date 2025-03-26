#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

ll nthroot(ll num, ll n){
    ll l = 1;
    ll r = num;
    while(l < r){
        ll mid = l + (r - l) / 2;
        ll ans = 1;
        for(ll i = 1; i <= n; i++){
            ans *= mid;
        }
        if(ans < num){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
     ll ans = 1;
    for(ll i = 1; i <= n; i++){
        ans *= l;
    }
    if(ans == num){
        return l;
    }
    ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ans *= r;
    }
    if (ans == num)
    {
        return r;
    }
    return -1;
}
int main(){
    fastio
    ll t;
    cin >> t;
    while(t--){
        ll num,n;
        cin >> num>>n;
        cout << nthroot(num, n) << endl;
    }
}