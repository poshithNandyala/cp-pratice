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
        int i = 0;
        int j = n - 1;
        bool ans = false;
        int mi = 1, mx = n;
        while ((j - i + 1) >= 4)
        {
            // if (a[i] != mi && a[j] != mi && a[i] != mx && a[j] != mx)
            // {
            //     ans = true;
            //     break;
            // }
            if ((a[i] == mi && a[j] == mx) || (a[j] == mi && a[i] == mx))
            {
                mi++;
                i++;
                mx--;
                j--;
            }
            else if (a[i] == mi)
            {
                mi++;
                i++;
            }
            else if (a[i] == mx)
            {
                mx--;
                i++;
            }
            else if (a[j] == mx)
            {
                mx--;
                j--;
            }
            else if (a[j] == mi)
            {
                mi++;
                j--;
            }
            else
            {
                ans = true;
                break;
            }
        }
        if (ans)
        {
            cout << i + 1 << " " << j + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}