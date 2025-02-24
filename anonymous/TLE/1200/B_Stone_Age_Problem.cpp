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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    map<int, int> mp;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[i] = a[i];
        sum += a[i];
    }
    ll g = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, x;
            cin >> i >> x;
            if (mp[i] == 0)
            {
                sum += (x - g);
            }
            else
            {
                sum += (x - mp[i]);
            }
            mp[i] = x;
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            g = x;
            mp.clear();
            sum = x * 1LL * n;
        }
        cout << sum << endl;
    }
}