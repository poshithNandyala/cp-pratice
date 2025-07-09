#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

vector<vector<int>> dp;
int n;
int rec(int i, int ch, vector<int> &a)
{
    if (i >= n)
        return 0;
    if (dp[i][ch] != -1)
    {
        return dp[i][ch];
    }
    if (ch == 0)
    {

        dp[i][0] = a[i] + rec(i + 1, 1, a);

        if (i + 1 < n)
        {
            dp[i][0] = min(dp[i][0], a[i] + a[i + 1] + rec(i + 2, 1, a));
        }

        return dp[i][0];
    }
    else
    {
        dp[i][1] = min(rec(i + 1, 0, a), rec(i + 2, 0, a));
        return dp[i][1];
    }
    return 0;
}
void iterative(int n, vector<int> &a)
{
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[i][0] = a[i] + dp[i + 1][1];
            if (i + 1 < n)
            {
                dp[i][0] = min(dp[i][0], a[i] + a[i + 1] + dp[i + 2][1]);
            }
            dp[i][1] = min(dp[i + 1][0], dp[i + 2][0]);
        }
    }
    cout << dp[0][0] << endl;
}
int32_t main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        // dp.resize(n + 1, vector<int>(2, -1));
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j < 2; j++)
        //     {
        //         dp[i][j] = -1;
        //     }
        // }
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // cout << rec(0, 0, a) << endl;
        iterative(n, a);
    }
}
