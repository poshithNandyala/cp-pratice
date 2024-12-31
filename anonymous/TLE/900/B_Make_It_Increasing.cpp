#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] == 0)
            {
                ans = -1;
                break;
            }
            while (a[i - 1] >= a[i])
            {
                a[i - 1] >>= 1;
                ans++;
            }
        }
        if (ans == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}