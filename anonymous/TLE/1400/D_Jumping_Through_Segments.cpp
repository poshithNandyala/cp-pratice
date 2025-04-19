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
        vector<pair<int, int>> a(n);
        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            cin >> a[i].second;
            if (i > 0)
            {
                hi = max(hi, abs(a[i].first - a[i - 1].first));
            }
        }
        hi=max(hi, abs(a[0].first - 0));
        while(lo<=hi){
            int mid = (lo + hi) / 2;
            bool ok = true;
            int l=0, r=0;
            for (int i = 0; i < n; i++)
            {
                l = max(a[i].first, l- mid);
                r = min(a[i].second, r + mid);
                if (l > r)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << hi+1 << endl;
    }
}