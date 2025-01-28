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
        int x, y, k;
        cin >> x >> y >> k;
        ll ans = 1;
        int c = 0, s = 2;
        if (x > y)
        {
            c = x / y;
            if (x % y == 0)
            {
                c--;
            }
            if (c > k)
            {
                x -= (k * y);
                ans = k;
            }
            if (c <= k)
            {
                int want = k - c;
                int rem = (x % y == 0) ? c : x % y;
            }
        }
    }