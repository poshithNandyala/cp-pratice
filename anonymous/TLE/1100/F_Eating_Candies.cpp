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
        int i = -1, j = n;
        ll left = 0, right = 0, l = 0, r = 0;
        ll ans = 0;
        while (i < j)
        {
            // cout<<"i"<<i<<"j"<<j<<endl;
            // cout << "left" << left << "right" << right << endl;
            // cout<<"ans"<<ans<<endl;
            // cout<<"l"<<l<<endl;
            // cout<<"r"<<r<<endl;
            if (left < right)
            {
                left += a[++i];
                l++;          
            }
            else if (left > right)
            {
                right += a[--j];
                r++;
            }
            else
            {
                // cout << "l" << l << "r" << r << endl;
                ans = max(ans, l + r);
                left += a[++i];
                l++;
            }
        }
        cout << ans << endl;
    }
}