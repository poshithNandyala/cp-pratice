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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if ((a[n - 1] < a[n - 2]))
        {
            cout << -1 << endl;
        }
        else if (is_sorted(a.begin(), a.end()))
        {
            cout << 0 << endl;
        }
        else
        {

            a[n - 3] = a[n - 2] - a[n - 1];
            if (a[n - 3] <= a[n - 2])
            {
                cout << n - 2 << endl;
                for (ll i = 0; i < n - 2; i++)
                {
                    cout << i + 1 << " " << n - 1 << " " << n << endl;
                }
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}
