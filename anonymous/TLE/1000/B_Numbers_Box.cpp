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
        int neg = 0;
        int a[n * m], mi = 1000000000, sum = 0;
        for (int i = 0; i < (n * m); i++)
        {
            cin >> a[i];
            if (a[i] < 0)
            {
                a[i] = abs(a[i]);
                neg++;
            }
            mi = min(mi, a[i]);
            sum += a[i];
        }
        if (neg % 2)
        {
            cout << sum - (2 * mi) << endl;
        }
        else
        {
            cout << sum << endl;
        }
    }
}