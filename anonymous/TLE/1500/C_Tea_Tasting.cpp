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
        ll n;
        cin >> n;
        vector<ll> a(n + 1), b(n + 1), mult(n + 2), add(n + 2), ans(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            ans[i] = b[i];
            b[i] += b[i - 1];
        }
        for (ll i = 1; i <= n; i++)
        {
            ll id = lower_bound(b.begin() + i, b.end(), a[i] + b[i - 1]) - b.begin();
            mult[i] += 1;
            // cout<<"id "<<id<<endl;
            mult[min(id + 1,n+1)] -= 1;
            if (id <= n)
            {
                add[id] += a[i] - b[id] + b[i - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            mult[i] += mult[i - 1];
            cout << ans[i] * mult[i] + add[i] << " ";
        }
        cout << endl;
    }
}