#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);


bool check(ll mid,ll k,ll x){
    ll req = 0;
    if(mid<=k){
        req += (((mid) * (mid + 1)) / 2);
    }
    else{
        req += (((k) * (k + 1)) / 2);
        mid -= k;
        req += ((k) * (k - 1)) / 2;
        req-= ((k-mid-1) * (k - mid)) / 2;
    }
    return req >= x;
}
int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        ll k, x;
        cin >> k >> x;
        ll lo = 1, hi = 2 * k - 1;
        ll ans = hi;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (check(mid,k,x))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }
}