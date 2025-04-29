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
        int five = 0, two = 0;
        map<ll, ll> m;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 10 == 0 || a[i] % 10 == 5)
            {
                five++;
                if (a[i] % 10 == 0)
                {
                    m[a[i]]++;
                }
                else
                {
                    m[a[i] + 5]++;
                }
            }
            else
            {
                two++;
                while (a[i] % 10 != 2)
                {
                    a[i] += (a[i] % 10);
                }
            }
        }

        if (five && two)
        {
            cout << "No" << endl;
            continue;
        }
        if (five)
        {
            if (m.size() == 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            sort(a.begin(), a.end());
            bool ok = true;
            for (ll i = 1; i < n; i++)
            {
                if ((a[i] - a[i - 1]) % 20 != 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}