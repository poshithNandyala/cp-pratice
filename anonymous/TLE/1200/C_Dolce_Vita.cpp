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
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < n; i++)
        {
            v[i] += v[i - 1];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= x)
            {
                ans += ((x - v[i]) / (i + 1)) + 1;
            }
            else{
                break;
            }
        }
        cout << ans << endl;
    }
}