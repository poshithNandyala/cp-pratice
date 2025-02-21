#include <bits/stdc++.h>
using namespace std;

int a[100008], b[100008];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, k = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i)
            cin >> a[i];
        sort(a + 1, a + m + 1);
        for (int i = 1; i < m; ++i)
            if (a[i] + 1 < a[i + 1])
                b[++k] = a[i + 1] - a[i] - 1;
        if (!(a[m] == n && a[1] == 1))
            b[++k] = n - a[m] + a[1] - 1;
        sort(b + 1, b + k + 1);
        int ans = n;
        for (int i = k; i; --i)
            if (b[i] > 4 * (k - i))
                ans -= max(1, b[i] - 4 * (k - i) - 1);
        cout << ans << '\n';
    }
}