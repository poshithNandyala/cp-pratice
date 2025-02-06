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
        int nn, k;
        cin >> nn >> k;
        int a[nn][nn], b[nn][nn];
        for (int i = 0; i < nn; i++)
        {
            for (int j = 0; j < nn; j++)
            {
                cin >> a[i][j];
            }
        }
        int n = 0, m = 0;
        for (int i = nn - 1; i >= 0; i--)
        {
            for (int j = nn - 1; j >= 0; j--)
            {
                b[n][m] = a[i][j];
                m++;
            }
            n++;
            m = 0;
        }
        int x = 0;
        for (int i = 0; i < nn/2; i++)
        {
            for (int j = 0; j < nn; j++)
            {
                if (b[i][j] != a[i][j])
                {
                    x++;
                }
            }
        }
        if(nn%2){
            for (int i = 0; i < nn/2; i++)
            {
                if (b[nn/2][i] != a[nn/2][i])
                {
                    x++;
                }
            }
        }
        // for (int i = 0; i < nn; i++)
        // {
        //     for (int j = 0; j < nn; j++)
        //     {
        //         cout << b[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << x << endl;

        bool ans = false;
        if (n % 2 && k >= x)
        {
            ans = true;
        }
        else if (n % 2 == 0 && k >= x && (k - x) % 2 == 0)
        {
            ans = true;
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