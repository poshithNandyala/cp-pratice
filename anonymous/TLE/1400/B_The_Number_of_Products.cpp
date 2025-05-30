#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    ll pos = 0, neg = 0, c = 1;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            a[i] = -1;
        }
        else
        {
            a[i] = 1;
        }
        c *= a[i];
        if (c == 1)
        {
            pos++;
        }
        else
        {
            neg++;
        }
    }
    ll ans1 = (pos * (pos - 1)) / 2 + pos + (neg * (neg - 1)) / 2;
    cout << (n * (n + 1)) / 2 - ans1 << " " << ans1 << endl;
}