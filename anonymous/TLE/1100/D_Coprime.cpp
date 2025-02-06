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
        int a[n], last[1001] = {};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            last[a[i]] = i+1;
        }
        int ans = -1;
        for (int i = 1; i <= 1000; i++)
        {
            if (!last[i])
                continue;
            for (int j = 1; j <= 1000; j++)
            {
                if (!last[j])
                    continue;
                if (__gcd(i, j) == 1)
                    ans = max(ans, last[i] + last[j]);
            }
        }
        cout << ans << endl;
    }
}