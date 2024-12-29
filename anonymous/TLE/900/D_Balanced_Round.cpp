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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = 0, c = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] > k)
            {
                ans = max(ans, c);
                c = 1;
            }
            else
            {
                c++;
            }
        }
        ans = max(ans, c);
        cout << n - ans << endl;
    }
}