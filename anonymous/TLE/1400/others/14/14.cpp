#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N = 1e6;
ll D, s;
vector<vector<ll>> a(N);
vector<vector<ll>> b(N);

void S(vector<ll> &v)
{
    sort(v.begin(), v.end());
    s = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        D += i * v[i] - s;
        s += v[i];
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            ll x;
            cin >> x;
            a[x].push_back(i);
            b[x].push_back(j);
        }
    }

    for (ll i = 1; i < N; i++)
        S(a[i]), S(b[i]);

    cout << D << endl;
    return 0;
}