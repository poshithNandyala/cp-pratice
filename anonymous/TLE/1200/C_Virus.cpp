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
        int n, m;
        cin >> n >> m;
        vector<int> a(m), v;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        v.push_back(n - a[m - 1] + a[0] - 1);
        for (int i = 1; i < m; i++)
        {
            v.push_back(a[i] - a[i - 1] - 1);
        }
        sort(v.begin(), v.end(), greater<int>());
        // for (auto item : v)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";

        int x = 0;
        ll ans = m;
        for (auto i : v)
        {
            if ((2 * x) >= i)
            {
                ans += i;
            }
            else if (((2 * x) + 1) == i || ((2 * x) + 2) == i)
            {
                ans += (i - 1);
                x++;
            }
            else if (((2 * x) + 1) < i)
            {
                ans += (2 * x) + 1;
                x+=2;
            }
            else{
                ans+=i;
            }
        }
        cout << ans << endl;
    }
}