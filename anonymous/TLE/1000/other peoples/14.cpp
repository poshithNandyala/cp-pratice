#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005], b[100005], l, ans;
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        ans = 1;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[j]);
            if (a[j] != a[j - 1])
            {
                if (j - 1 == l && l != 0 && ans)
                {
                    cout << -1 << "\n";
                    ans = 0;
                }
                b[l] = j - 1;
                l = j;
            }
            else
            {
                b[j] = j - 1;
            }
        }
        b[l] = n;
        if (ans)
        {
            if (a[n] != a[n - 1])
            {
                cout << -1 << "\n";
                continue;
            }
            for (int j = 1; j <= n; j++)
            {
                cout << b[j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}