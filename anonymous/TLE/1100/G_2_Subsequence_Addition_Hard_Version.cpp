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
        bool ans = true;
     
        sort(a, a + n);
        if (a[0] != 1)
        {
            ans = false;
        }
        ll sum = a[0];

        if (ans)
        {
            for (int i = 1; i < n; i++)
            {
                if (a[i] > sum)
                {
                    ans = false;
                    break;
                }
                sum += a[i];
            }
        }

        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}