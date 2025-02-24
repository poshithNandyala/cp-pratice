#include <bits/stdc++.h>
using namespace std;
long long a[222222];
map<int, int> mp;
void fuckkk()
{
    long long n, q, ans{0}, lst;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
        mp[i] = 1;
    }

    while (q--)
    {
        long long f, x, y;
        cin >> f >> x;
        if (f == 1)
        {
            cin >> y;
            if (!mp[x])
            {
                mp[x] = 1;
                ans -= lst;
                ans += y;
                a[x] = y;
            }
            else
            {
                ans -= a[x];
                ans += y;
                a[x] = y;
            }
        }
        else
        {
            lst = x;
            ans = n * x;
            mp.clear();
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    //	cin>>_;
    while (_--)
    {
        fuckkk();
    }
    return 0;
}