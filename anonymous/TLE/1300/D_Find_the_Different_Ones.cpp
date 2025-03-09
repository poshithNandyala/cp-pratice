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
        vector<int> a(n), l(n), r(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int k = -1;
        l[0] = k;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                l[i] = k;
            }
            else
            {
                k = (i - 1);
                l[i] = k;
            }
        }
        k = n + 1;
        r[n - 1] = k;
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] == a[i + 1])
            {
                r[i] = k;
            }
            else
            {
                k = (i + 1);
                r[i] = k;
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int lll, rrr;
            cin >> lll >> rrr;
            lll--;
            rrr--;
            int ans = -1;
            if (l[lll] >= lll && l[lll] <= rrr)
            {
                ans = l[lll] + 1;
            }
            else if (r[lll] >= lll && r[lll] <= rrr)
            {
                ans = r[lll] + 1;
            }
            if (ans == -1)
            {
                cout << -1 << " " << -1 << endl;
            }
            else
            {
                cout << lll+1 << " " << ans << endl;
            }
        }
        cout << endl;
    }
}