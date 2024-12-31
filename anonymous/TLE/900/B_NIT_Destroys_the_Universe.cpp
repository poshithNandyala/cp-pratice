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
        int start = 0, end = n - 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                start++;
            }
            else
            {
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 0)
            {
                end--;
            }
            else
            {
                break;
            }
        }
        if (start > end)
        {
            cout << 0 << endl;
        }

        else
        {
            int ans = 0;
            for (int i = start; i <= end; i++)
            {
                if (a[i] == 0)
                {
                    ans++;
                }
            }
            if (ans)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }
}