// Write your code here
#include <bits/stdc++.h>
using namespace std;
vector<int> a(100005);
int n, k;
bool check(int mid)
{
    int req = n + 1;
    for (int i = mid; i <= n; i++)
    {
        req = min(req, mid-(a[i] - a[i - mid]));
    }
    return req > k;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int hi = n;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        int lo = 1;
        int ans = hi + 1;
        while (lo <= hi)
        {
            int mid = (lo + ((hi - lo) / 2));
            if (check(mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans - 1 << endl;
    }
}