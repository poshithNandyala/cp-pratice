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
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        vector<vector<ll>> b(32);
        for(int i = 0; i < 32; i++){
            b[i].push_back(0);
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 0; j < 32; j++)
            {
                if (a[i] & (1LL << j))
                {
                    b[j].push_back(b[j][i-1]+0);
                }
                else
                {
                    b[j].push_back(b[j][i - 1] + 1);
                }
            }
        }
        // for (auto item : b)
        // {
        //     for (auto it : item)
        //     {
        //         cout << it << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n";
        // for (int i = 0; i < 32; i++)
        // {
        //     for (int j = 1; j < n; j++)
        //     {
        //         b[i][j] += b[i][j - 1];
        //     }
        // }
        // for (auto item : b)
        // {
        //     for (auto it : item)
        //     {
        //         cout << it << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n";

        ll q;
        cin >> q;
        while (q--)
        {
            ll l, k;
            cin >> l >> k;
            ll ans = -1;
            ll lo = l, hi = n;
            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                ll cnt = 0;
                for (int j = 0; j < 32; j++)
                {
                    if (!(b[j][mid] - b[j][l - 1]))
                    {
                        cnt += (1LL << j);
                    }
                }
                if (cnt >= k)
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}