#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio;
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 1;
    ll lo = 1, hi = n;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        vector<ll> temp;
        for(ll i=0;i<mid;i++){
            temp.push_back(a[i]);
        }
        sort(temp.begin(),temp.end());
        ll sum = 0;
        for(ll i=temp.size()-1;i>=0;i-=2){
            sum += temp[i];
        }
        if(sum<=h){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}