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
        int a[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    
        int x = n / 2;
        // cout<<"x = "<<x<<endl;
        int c = 1, ans = 0;
        int i = n;
        int v = a[n];
        for (i = (n - 1); i > x; i--)
        {
            if (a[i] != v)
            {
                i -= (c - 1);
                x=min(x,i-1);
                ans++;
                c *= 2;
            }
            else
            {
                c++;
            }
        }
        // cout << x << " " << ans << endl;
        for (int j = 1; j <= x; j++)
        {
            if (a[j] != v)
            {
                ans++;
                break;
            }
        }
        cout << ans << endl;
    }
}