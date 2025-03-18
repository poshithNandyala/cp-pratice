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
        vector<int> a(n + 1), b(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int v = 1, m = 0, ans = 0, i = 1, j = 1;
        while (i <= n && j <= n)
        {
            while (j <= n && a[j] >= (j - m))
            {
                b[j] = i;
                j++;
                if (j <= n && a[j] < (j - m))
                {
                    j--;
                    break;
                }
            }
            m++;
            i++;
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     int x = 1, k = 2;
        //     for (int j = i - 1; j >= 1; j--)
        //     {
        //         if (a[j] >= k)
        //         {
        //             x++;
        //             k++;
        //         }
        //     }
        //     cout << x << " ";
        // }
        // cout << endl;

        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << " ";
        }
        cout << "\n";

        for (int i = 1; i <= n; i++)
        {
            if (i - b[i] > 0)
            {
                cout << i - b[i] << " ";
            }
            else
            {
                cout << "1 ";
            }
        }
        cout << endl;
    }
}