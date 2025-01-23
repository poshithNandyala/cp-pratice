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
        ll n, x;
        cin >> n >> x;
        int a[n], c = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int mi = INT_MAX, ma = -1, ans = 0,id;
        for (int i = 0; i < n; i++)
        {
            mi = min(mi, a[i]);
            ma = max(ma, a[i]);
            if ((ma - mi) > (2 * x))
            {
                ans++;
                mi = INT_MAX;
                ma = -1;
                i--;
            }
        }
        cout << ans << endl;
    }
}