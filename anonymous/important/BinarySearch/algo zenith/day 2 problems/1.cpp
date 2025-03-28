// Write your code here
#include <bits/stdc++.h>
using namespace std;
vector<int> a(100005);
int n, k;
bool check(int mid)
{
    int req = 0;
    for (int i = 2; i <= n; i++)
    {
        req += (((a[i] - a[i - 1] + (mid - 1)) / mid) - 1);
    }
    return req <= k;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int hi = 0;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            hi = max(hi, a[i] - a[i - 1]);
        }
        int lo = 1;
        int ans = hi;
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
        cout << ans << endl;
    }
}