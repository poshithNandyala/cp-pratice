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
        int rem[m] = {};
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            rem[x % m]++;
        }
        int ex = 0, ans = 0;
        for (int i = 1; i <= (m / 2); i++)
        {
            int mi = min(rem[i], rem[m - i]);
            int ma = max(rem[i], rem[m - i]);
            if (mi == ma && ma != 0)
            {
                ans++;
            }
            else if (((mi + 1 )<= ma))
            {
                ans++;
                ex+=(ma-mi-1);
            }
        }
        if (rem[0] > 0)
        {
            ans++;
        }
        cout<<ans+ex<<endl;
    }
}