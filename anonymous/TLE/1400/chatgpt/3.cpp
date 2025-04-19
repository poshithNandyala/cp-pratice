#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canWithK(const vector<pair<ll, ll>> &segs, ll k)
{
    // After 0 moves, we're exactly at x=0
    ll L = 0, R = 0;
    for (size_t i = 0; i < segs.size(); ++i)
    {
        ll l = segs[i].first;
        ll r = segs[i].second;
        // expand [L,R] by +/- k, then intersect with [l,r]
        ll newL = max(l, L - k);
        ll newR = min(r, R + k);
        if (newL > newR)
            return false;
        L = newL;
        R = newR;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> segs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> segs[i].first >> segs[i].second;
        }

        ll lo = 0, hi = 1000000000LL, ans = hi;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (canWithK(segs, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
