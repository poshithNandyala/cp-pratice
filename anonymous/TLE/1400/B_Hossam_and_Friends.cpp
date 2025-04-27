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
        vector<ll> r(n+1, 0);
        for (ll i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            r[max(a, b)] = max(r[max(a, b)], min(a, b));
        }
        ll ans = 0;
        // for(auto item : r){
        //     cout << item << " ";
        // }
        // cout << "\n";
        ll len = 1;
        for (ll i = 1; i <= n; i++)
        {
            len=min(len, i-r[i]);
            ans+= len;
            len++;
        }
        // cout << ans << endl;
        // ans += n;
        cout << ans << endl;
    }
}