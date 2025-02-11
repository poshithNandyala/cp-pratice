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
        ll x = (n * (n - 1)) / 2;
        map<ll, ll> mp;
        for (int i = 0; i < x; i++)
        {
            ll a;
            cin >> a;
            mp[a]++;
        }
        ll ans = n - 1;
        for (auto i : mp)
        {
            while (i.second > 0)
            {
                i.second -= ans;
                cout << i.first << " ";
                ans--;
            }
        }
        auto it = mp.end();
        it--;
        cout << (it->first) << endl;
    }
}