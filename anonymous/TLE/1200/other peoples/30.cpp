#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        vector<ll> a;
        vector<ll> b;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] == v[0])
                a.push_back(i + 1);
            else
                b.push_back(i + 1);
        }
        if (a.size() == n)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (ll i = 0; i < a.size(); i++)
            {
                cout << a[i] << " " << b[0] << endl;
            }
            for (ll i = 1; i < b.size(); i++)
            {
                cout << b[i] << " " << a[0] << endl;
            }
        }
    }
}