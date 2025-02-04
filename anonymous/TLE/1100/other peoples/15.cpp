#include <bits/stdc++.h>

using namespace std;
#define int long long
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s += s;
    int res = 0;
    for (int i = 0; i < 2 * n;)
    {
        int j = i + 1;
        while (j < 2 * n && s[i] == s[j])
            j++;
        if (s[i] == '1')
            res = max(res, min(n, j - i));
        i = j;
    }
    int mid = res >> 1;
    if (res == n)
    {
        cout << n * n << "\n";
        return;
    }
    cout << (mid + 1) * (res - mid) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}