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
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        map<ll, vector<ll>> mpy;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            mpy[a[i] % y].push_back(a[i]);
        }
  
        ll ans = 0;
        for (auto i : mpy)
        {
            map<ll, ll> mpx;
            for (ll j = 0; j < i.second.size(); j++)
            {
                mpx[i.second[j] % x]++;
            }
            for (auto j : mpx)
            {
                if (j.first > (x / 2))
                {
                    break;
                }
                else if (j.first == 0)
                {
                    ans += ((mpx[0] * (mpx[0] - 1)) / 2);
                }
                else if (x % 2 == 0 && j.first == x / 2)
                {
                    ans += ((mpx[x / 2] * (mpx[x / 2] - 1)) / 2);
                }
                else
                {
                    ans += (mpx[j.first] * mpx[x - j.first]);
                }
            }
        }
        cout << ans << endl;
    }
}