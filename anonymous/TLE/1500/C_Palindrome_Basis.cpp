#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
vector<int> a;
bool isPalindrrome(int n)
{
    string s = to_string(n);
    string t = s;
    reverse(s.begin(), s.end());
    return s == t;
}
int main()
{
    fastio int t;
    cin >> t;
    int n = 400002;
    for (int i = 1; i <= n; i++)
    {
        if (isPalindrrome(i))
        {
            a.push_back(i);
        }
    }
    const int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = a[i]; j <= n; j++)
        {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    while (t--)
    {
        int n;
        cin >> n;

        cout << dp[n] << endl;
    }
}