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
        int ans = 0;
        int x = k, y = k;
        if (x % 2 == 0)
        {
            x--;
        }
        else
        {
            y--;
        }
        if (n % 2)
        {
            n -= min(n, x);
            ans++;
        }
        ans += (n / y);

        if ((n % y) != 0)
        {
            ans++;
        }
        cout << ans << endl;
    }
}