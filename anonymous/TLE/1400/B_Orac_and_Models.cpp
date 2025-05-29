#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
int n;
vector<int> a, dp;

int func(int i)
{
    if (i == n)
        return 0;
    int ans = 0;
    for (int j = 2 * i; j <= n; j += i)
    {
        if (a[j] > a[i])
        {
            if (dp[j] == -1)
            {
                dp[j] = func(j);
            }
            ans = max(ans, 1 + dp[j]);
        }
    }
    return ans;
}
int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        a = vector<int>(n + 1);
        dp = vector<int>(n + 1, -1);
        dp[0] = 0;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int mx = 1;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == -1)
            {
                dp[i] = func(i);
            }
            mx = max(mx, 1 + dp[i]);
        }
        cout << mx << endl;
    }
}