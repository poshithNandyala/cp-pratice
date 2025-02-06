#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int T, n;
int a[N], las[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= 1000; ++i)
            las[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            las[a[i]] = i;
        }
        int ans = -1;
        for (int i = 1; i <= 1000; ++i)
        {
            if (!las[i])
                continue;
            for (int j = 1; j <= 1000; ++j)
            {
                if (!las[j])
                    continue;
                if (__gcd(i, j) == 1)
                    ans = max(ans, las[i] + las[j]);
            }
        }
        cout << ans << "\n";
    }
}