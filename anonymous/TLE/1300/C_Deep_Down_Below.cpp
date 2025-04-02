#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> ans;
        ll lo = 2, hi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            ll mx = INT_MIN;
            for (int j = 0; j < x; j++)
            {
                ll y;
                cin >> y;
                hi = max(hi, y);
                mx = max(mx, (y - j));
            }
            ans.push_back({mx, x});
        }
        sort(ans.begin(), ans.end());
        hi += 1;
        ll ans1 = INT_MIN;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll req = 0;
            bool anss = true;
            ll v = mid;
            for (int i = 0; i < n; i++)
            {
                if (ans[i].first >= v)
                {
                    anss = false;
                    break;
                }
                v += ans[i].second;
            }
            if (anss)
            {
                ans1 = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans1 << endl;
    }
}