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
    int i = 0;
    while (t--)
    {
        i++;
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        ll mi = (k - 1) * (n), ma = s / k;
        if (s <= mi)
        {
            mi = 0;
        }
        else
        {
            mi = ((s - mi) + (k - 1)) / k;
        }
        bool ans = false;

        if (ma >= b && mi <= b)
        {
            ans = true;
        }

        if (ans)
        {
            ll a = b * k;
            a += min((k - 1), s - a);
            s -= a;
            cout << a << " ";

            for (ll i = 0; i < n - 1; i++)
            {
                // cout << "s" << s << endl;
                if (s <= 0)
                {
                    cout << 0 << " ";
                }
                else if (s >= k)
                {
                    cout << k - 1 << " ";
                    s -= (k - 1);
                }
                else
                {
                    cout << s << " ";
                    s = 0;
                }
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}