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
        ll n, k;
        cin >> n >> k;
        ll mx = 1;
        for (ll i = 1; i * i <= n; i++)
        {
            if ((n % i == 0) && (i <= k))
            {
                mx = max(mx, i);
                if ((i != n / i) && ((n / i) <= k))
                {
                    mx = max(mx, n / i);
                }
            }
        }
        cout << n / mx << endl;
    }
}