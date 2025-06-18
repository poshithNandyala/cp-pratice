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
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        // for (auto item : a)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";

        ll i = 0, j = n - 1, x = 0, ans = 0;
        while (i < j)
        {
            if (x == a[j])
            {
                x = 0;
                a[j] = 0;
                j--;
                ans += 1;
            }
            else if ((a[j] - x) < a[i])
            {
                a[i] -= (a[j] - x);
                ans += (a[j] - x);
                j--;
                x = 0;
                ans++;
            }
            else
            {
                x += a[i];
                ans += a[i];
                a[i] = 0;
                i++;
            }
        }
        // cout << a[i] << " " << x << endl;
        ll ans1 = ((a[i] - x + 1) / 2) + 1;
        if (a[i] == 1)
        {
            ans1 = 1;
        }
        // there will be no testace that a[i] < x;
        cout << ans + ans1 << endl;
    }
}