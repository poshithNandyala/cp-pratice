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
        int n, k, m = 0;
        cin >> n >> k;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        ll ans = 0;
        ll mainsum = 0;
        for (int i = 0; i < min(n, k); i++)
        {
            int mul = k - i - 1;
            mainsum += a[i];
            m = max(m, b[i]);
            ans = max(ans, mainsum + mul * 1LL * m);
        }
        cout << ans << endl;
    }
}