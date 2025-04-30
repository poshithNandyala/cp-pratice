#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);


int main()
{
    fastio ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(m);
        map<ll,ll> mp;
        for (ll i = 0; i < m; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        // for(auto it:mp){
        //     cout << it.first << " " << it.second << endl;
        // }
        // cout << endl;
        ll l = 1, r = m, ans = 1;
        
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll have = mid;
            if(mid%2){
                have--;
            }
            have*=(n-mp.size());
            ll left = 0;
            for(auto it:mp){
              if(it.second <= mid){
                  have += (mid-it.second);
                  if((mid-it.second)%2){
                     have--;
                  }
              }
              else{
                left += (it.second-mid);
              }
            }
            if (2*left <= have)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}