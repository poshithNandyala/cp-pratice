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
        ll sum = 0;
        int neg = 0;
        int a[n];
        int mi = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] < 0)
            {
                neg++;
            }
            sum += abs(a[i]);
            mi = min(mi, abs(a[i]));
        }
        if ( ((neg % 2) == 0))
        {
            cout << sum << endl;
        }
        else
        {
            cout << sum - 2 * mi << endl;
        }
    }
}