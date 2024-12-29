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
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int ans = abs(a[0] - 1);
        for (int i = 1; i < n; i++)
        {

            ans = __gcd(ans, abs(a[i] - (i + 1)));
        }
        cout << ans << endl;
    }
}