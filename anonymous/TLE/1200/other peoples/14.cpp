#include <bits/stdc++.h>
using namespace std;
string s[100006];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < (n + 1) / 2; i++)
            for (int j = 0; j < n / 2; j++)
            {
                int t = s[i][j] - '0' + s[j][n - i - 1] - '0' + s[n - i - 1][n - j - 1] - '0' + s[n - j - 1][i] - '0';
                ans += min(t, 4 - t);
            }
        cout << ans << endl;
    }
}