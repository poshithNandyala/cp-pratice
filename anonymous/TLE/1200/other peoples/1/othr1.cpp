#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, dp[8];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (cin >> n; cin >> n; cout << dp[7] << endl)
    {
        for (int i = 0; i < 8; i++)
            dp[i] = 0;
        int a[3][n];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
        {
            for (int j = 7; j >= 1; --j)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j & (1 << k))
                        dp[j] = max(dp[j], dp[j - (1 << k)] + a[k][i]);
                }
            }
        }
    }
    return 0;
}