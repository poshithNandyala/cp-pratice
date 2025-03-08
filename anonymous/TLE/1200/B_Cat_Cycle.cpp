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
        if (n % 2)
        {
            ll val = n / 2;
            ll fval = val + 1;
            if (k < fval)
            {
                cout << k << endl;
            }
            else if (k == fval)
            {
                cout << fval + 1 << endl;
            }
            else
            {
                ll ans = fval + 1;
                ans += ((k - fval) / val);
                ans += (k - fval);
                cout << ((ans % n)?(ans % n):n) << endl;
            }
        }
        else
        {
            cout << ((k % n) ? (k % n) : n) << endl;
        }
    }
}