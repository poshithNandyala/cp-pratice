#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int l = 0, r = n - 1, f = 1, la = n;
        while (l <= r)
        {
            if (a[l] == f)
                l++, f++;
            else if (a[r] == f)
                r--, f++;
            else if (a[l] == la)
                l++, la--;
            else if (a[r] == la)
                r--, la--;
            else
                break;
        }
        if (l <= r)
            cout << l + 1 << " " << r + 1 << '\n';
        else
            cout << -1 << '\n';
    }
}