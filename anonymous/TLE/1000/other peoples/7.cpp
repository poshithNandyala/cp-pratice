#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], n;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int lst = a[1], cnt = 1, ans = 1;
    map<int, int> mp;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == lst)
            cnt++;
        else
            mp[lst] = max(mp[lst], cnt), lst = a[i], cnt = 1;
        ans = max(ans, cnt);
    }
    mp[lst] = max(mp[lst], cnt);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    lst = a[1], cnt = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == lst)
            cnt++;
        else
        {
            ans = max(ans, mp[lst] + cnt);
            lst = a[i], cnt = 1;
        }
        ans = max(ans, cnt);
    }
    ans = max(ans, mp[lst] + cnt);
    printf("%d\n", ans);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}