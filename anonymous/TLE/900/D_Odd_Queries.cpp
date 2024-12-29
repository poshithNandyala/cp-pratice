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
        int n, q;
        cin >> n >> q;
        ll a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        while (q--)
        {
            ll l, r, k;
            cin >> l >> r >> k;
            ll sum = a[r] - a[l - 1];
            ll newsum = (r - l + 1) * k;
            bool ans = false;
            if ((sum % 2) == (newsum % 2))
            {
                ans = true;
            }
            if (((a[n] % 2) && (ans)) || (!(a[n] % 2) && !(ans)))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}