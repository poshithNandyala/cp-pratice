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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int gcd = 0;
        map<int, int> mp;
        for (int i = 0; i < n / 2; i++)
        {
            if (a[i] != a[n - 1 - i])
            {
                mp[abs(a[i] - a[n - 1 - i])]++;
                gcd = __gcd(gcd, abs(a[i] - a[n - 1 - i]));
            }
        }

        // if (mp.size() > 1)
        // {
        //     cout << gcd << endl;
        // }
        // else if (mp.size() == 1)
        // {
        //     cout << max(mp.begin()->first, gcd) << endl;
        // }
        // else
        // {
        //     cout << 0 << endl;
        // }
        cout << gcd << endl;
    }
    return 0;
}