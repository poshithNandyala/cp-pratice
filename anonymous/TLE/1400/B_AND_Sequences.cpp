#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
ll mod = 1e9 + 7;

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll an;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
            {
                an = a[i];
            }
            else
            {
                an &= a[i];
            }
        }
        ll mi = *min_element(a.begin(), a.end());
        ll c = count(a.begin(), a.end(), mi);
        // cout<<"c: "<<c<<" mi: "<<mi<<" an: "<<an<<endl;
        if (an != mi || c == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            ll ans = 1;
            for (int i = 1; i <= (n - 2); i++)
            {
                ans = (ans * i) % mod;
            }
            // cout<<"ans: "<<ans<<endl;
            c = ((c % mod) * (c - 1) % mod) % mod;
            // cout<<"c: "<<c<<endl;
            ans = (ans * c) % mod;
            cout << (ans) % mod << endl;
        }
    }
}