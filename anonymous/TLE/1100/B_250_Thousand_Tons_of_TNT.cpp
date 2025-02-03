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
        ll a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        // for (auto item : a)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";

        ll ans1 = -1, ans2 = 1e18, ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans1 = -1;
            ans2 = 1e18;
            if (n % i == 0)
            {
                for (int j = i; j <= n; j += i)
                {
                    // cout << "i" << i << " j" << j << " " << a[j] - a[j - i] << endl;
                    ans1 = max(ans1, a[j] - a[j - i]);
                    ans2 = min(ans2, a[j] - a[j - i]);
                }
                // cout << "ans1" << ans1 << "ans2" << ans2 << endl;
                ans = max(ans, ans1 - ans2);
            }
       
        }
        cout << ans << endl;
    }
}