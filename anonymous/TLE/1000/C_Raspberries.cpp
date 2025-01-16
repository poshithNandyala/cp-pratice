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
        int n, k;
        cin >> n >> k;
        int a[n], odd = 0, even = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            if (a[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        int ans = 0;

        if (k == 2 && !even)
        {
            ans = 1;
        }
        else if (k == 3 && mp[3] == 0 && mp[6] == 0 && mp[9] == 0)
        {
            if (mp[2] || mp[5] || mp[8])
            {
                ans = 1;
            }
            else
            {
                ans = 2;
            }
        }
        else if (k == 4 && mp[4] == 0 && mp[8] == 0)
        {
            if (mp[3] || mp[7])
            {
                ans = min(1, max(0, 2 - even));
            }
            else
            {

                ans = max(0, 2 - even);
            }
        }
        else if (k == 5 && mp[5] == 0 && mp[10] == 0)
        {
            if (mp[4] || mp[9])
            {
                ans = 1;
            }
            else if (mp[3] || mp[8])
            {
                ans = 2;
            }
            else if (mp[2] || mp[7])
            {
                ans = 3;
            }
            else
            {
                ans = 4;
            }
        }

        cout << ans << endl;
    }
}