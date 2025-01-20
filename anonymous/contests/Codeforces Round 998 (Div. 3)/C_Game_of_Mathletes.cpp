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
        int n, k;
        cin >> n >> k;
        vector<int> v(k, 0);
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x >= k)
            {
                c++;
            }
            else
            {
                v[x]++;
            }
        }
        ll ans = 0, extra = 0,ex=0;
        bool flag = false;
        for (int i = 1; i <= (k) / 2; i++)
        {
            if (i == k / 2 && k % 2 == 0)
            {
                ans += v[i] / 2;
            }
            else
            {
                if (v[i] * v[k - i] == 0 && (v[i] != 0 || v[k - i] != 0))
                {
                    extra += (v[i] + v[k - i]);
                }
                int mi = min(v[i], v[k - i]);
                int mx = max(v[i], v[k - i]);
                ans += mi;
                ex += mx - mi;
            }
        }
        // cout << "c" << c << endl;
        c+= extra;
        // if (c % 2 && ex==0)
        // {
        //     ans -= 1;
        // }
        cout << ans << endl;
    }
}