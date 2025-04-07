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
        int n, x, m;
        cin >> n >> x >> m;
        int hi = x, lo = x;
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            if (lo >= l && lo <= r)
            {
                lo = min(lo, l);
                hi = max(hi, r);
            }
            if(hi >= l && hi <= r)
            {
                lo = min(lo, l);
                hi = max(hi, r);
            }
            // cout<<lo << " " << hi << endl;
        }
        cout << hi - lo + 1 << endl;
    }
}