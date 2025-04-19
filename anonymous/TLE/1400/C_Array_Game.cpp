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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (k > 2)
        {
            cout << 0 << endl;
            continue;
        }
        sort(a.begin(), a.end());
        ll mi = a[0];

        // Always check basic difference
        for (int i = 1; i < n; i++)
        {
            mi = min(mi, a[i] - a[i - 1]);
        }

        if (k == 2)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    ll x = a[i] - a[j];
                    mi = min(mi, x); // <-- This was missing

                    auto it = lower_bound(a.begin(), a.end(), x);
                    if (it != a.end())
                        mi = min(mi, abs(*it - x));
                    if (it != a.begin())
                    {
                        --it;
                        mi = min(mi, abs(*it - x));
                    }
                }
            }
        }

        cout << mi << endl;
    }
}
