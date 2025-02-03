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
        int n, x;
        cin >> n >> x;
        int a[n], b[n], c[n], d[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            if ((x | a[i]) == x)
            {
                ans |= a[i];
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {

            if ((x | b[i]) == x)
            {
                ans |= b[i];
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {

            if ((x | c[i]) == x)
            {
                ans |= c[i];
            }
            else
            {
                break;
            }
        }
        // cout << ans << endl;
        if (ans == x)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}