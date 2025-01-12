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
    int t;
    cin >> t;
    ll x = 1;
    vector<ll> v;
    for (ll i = 0; i < 40; i++)
    {
        x <<= 1;
        v.push_back(x);
    }
    while (t--)
    {
        ll n;
        cin >> n;
        if(find(v.begin(), v.end(), n) != v.end())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        
    }
    return 0;
}
