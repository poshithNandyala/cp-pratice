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
        ll n, c;
        cin >> n >> c;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll low = 1, high = 1e9;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            ll cnt = 0;
            for (int i = 0; i < n; i++)
            {
                cnt += ((v[i] + 2 * mid) * (v[i] + 2 * mid));
                if (cnt > c)
                {
                    break;
                }
            }
            if (cnt > c)
            {
                high = mid - 1;
            }
            else if (cnt == c)
            {
                cout << mid << endl;
                break;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
}
