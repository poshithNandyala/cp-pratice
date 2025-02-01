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
        int sum = 0;
        int sum1 = -10000;
        bool ans = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (abs(a[i]) % 2 + abs(a[i + 1]) % 2 == 1)
            {
                if (sum < 0)
                {
                    sum = 0;
                }
                sum += a[i];
                sum1 = max(sum, sum1);
            }
            else
            {
                if (sum < 0)
                {
                    sum = 0;
                }
                sum += a[i];
                sum1 = max(sum, sum1);
                sum = 0;
            }
        }
        if (sum < 0)
        {
            sum = 0;
        }
        sum += a[n - 1];
        sum1 = max(sum, sum1);
        cout << sum1 << endl;
    }
}