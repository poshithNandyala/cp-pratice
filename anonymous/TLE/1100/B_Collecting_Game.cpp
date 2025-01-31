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
        vector<ll> a(n), b(n), c(n);
        map<ll, ll> mp;
        ll v[n] = {};
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            c[i] = a[i];
        }
        sort(a.begin(), a.end());
        b[0] = a[0];
        for (ll i = 1; i < n; i++)
        {
            b[i] = a[i];
            a[i] += a[i - 1];
        }
        ll cnt = 0;
        for (ll i = n - 1; i > 0; i--)
        {
            if (a[i] - a[i - 1] <= a[i - 1])
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            v[i - 1] = cnt;
        }
        // for (auto item : b)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";
        // for (auto item : a)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";

        // for (auto item : v)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";
        // cout << "-----------------------------------\n";
        for (ll i = 0; i < n; i++)
        {
            if (b[i] != b[i - 1])
            {
                mp[b[i]] += i;
                mp[b[i]] += v[i];
            }
        }
        mp[b[n - 1]] = 0;
        mp[b[n - 1]] += (n - 1);
        for (ll i = 0; i < n; i++)
        {
            cout << mp[c[i]] << " ";
        }
        cout << endl;
    }
}           