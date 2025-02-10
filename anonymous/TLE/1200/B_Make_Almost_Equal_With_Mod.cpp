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
    vector<ll> v;
    ll power = 1;
    for (int i = 1; i < 61; i++)
    {

        power *= 2;
        v.push_back(power);
    }
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll i = 0;
        while (i < 64)
        {
            map<ll, ll> mp;
            for (ll j = 0; j < n; j++)
            {
                mp[a[j] % v[i]]++;
                if(mp.size() == 2)
                {
                    break;
                }
            }
            if (mp.size() == 2)
            {
                cout << v[i] << endl;
                break;
            }
            i++;
        }
    }
}