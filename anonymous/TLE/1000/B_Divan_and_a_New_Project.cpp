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
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v;
        vector<ll> an;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            an.push_back(x);
            v.push_back({x, i + 1});
        }
        sort(v.begin(), v.end(), greater<pair<ll, ll>>());
        ll t1 = 0;
        vector<pair<ll, ll>> ans;
        ll x = 1;
        for (ll i = 0; i < n; i++)
        {
            t1 += 2*(abs(v[i].first * x));
            ans.push_back({v[i].second, x});
            x *= -1;
            i++;
            if (i < n)
            {
                t1 += 2*(abs(v[i].first * x));
                ans.push_back({v[i].second, x});
                x *= -1;
            }
            x++;
        }
        sort(ans.begin(), ans.end());
        cout << t1 << endl;
        cout << 0 << " ";
        for (auto i : ans)
        {
            cout << i.second << " ";
        }
        cout << endl;
    }
}