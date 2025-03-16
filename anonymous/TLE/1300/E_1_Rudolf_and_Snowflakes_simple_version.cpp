#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio
        ll t;
    cin >> t;
    ll n = 1000005;
    vector<bool> ans(n);
    for (ll i = 2; i <= n; i++)
    {
        ll ans1 = 1 + i + (i * i);
        ll x = i * i;
        while (ans1 <= n)
        {
            x *= i;
            ans[ans1] = true;
            ans1 += x;
        }
    }
    while (t--)
    {
        ll n;
        cin >> n;
        if (ans[n])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}