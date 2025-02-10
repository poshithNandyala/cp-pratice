#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long i, n, x = 0;
        cin >> n;
        long long a[n];
        for (i = 0; i < n; ++i)
            cin >> a[i];
        for (i = 0; i < n - 1; ++i)
        {
            x = __gcd(x, abs(a[i] - a[i + 1]));
        }
        cout << 2 * x << endl;
    }
}