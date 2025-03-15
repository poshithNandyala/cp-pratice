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
        vector<int> a(n);
        map<ll, int> mp;
        ll sum = 0;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i % 2)
            {
                sum += a[i];
            }
            else
            {
                sum -= a[i];
            }
            mp[sum]++;
            if (mp[sum] >= 2 || sum == 0)
            {
                ans = true;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}