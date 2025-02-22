#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        int a[n][n], b[n][n], c[n][n], d[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = s[i][j] - '0';
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[i][j] = a[n - j - 1][i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = b[n - j - 1][i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = c[n - j - 1][i];
            }
        }
        // cout << "a" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "b" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << b[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "c" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << c[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "d" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << d[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ct = (a[i][j] + b[i][j] + c[i][j] + d[i][j]);
                if (ct == 2)
                {
                    ans += 2;
                }
                else if (ct == 3 || ct == 1)
                {
                    ans += 1;
                }
            }
        }
        cout << ans/4 << endl;
    }
}