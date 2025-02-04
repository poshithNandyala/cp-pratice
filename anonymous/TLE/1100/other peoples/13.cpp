#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, gcd;
    vector<int> arr;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.assign(n, 0);
        for (i = 0; i < n; i++)
            cin >> arr[i];

        gcd = abs(arr[n - 1] - arr[0]);
        for (i = 1; i < n / 2; i++)
            gcd = __gcd(gcd, abs(arr[i] - arr[n - 1 - i]));

        cout << gcd << '\n';
    }
    return 0;
}