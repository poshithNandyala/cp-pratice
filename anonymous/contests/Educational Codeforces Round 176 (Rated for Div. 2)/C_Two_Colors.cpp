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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(m), pf(m + 1);
        pf[m] = 0;
        map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a.begin(), a.end());
        pf[m - 1] = a[m - 1];
        for (int i = (m - 2); i >= 0; i--)
        {
            pf[i] = pf[i + 1] + a[i];
        }
        for (auto item : a)
        {
            cout << item << " ";
        }
        cout << "\n";
        for (auto item : pf)
        {
            cout << item << " ";
        }
        cout << "\n";

        ll sum = 0;

        ll ans = 0;
        for (int i = 0; i < m; i++)
        {
            auto it = lower_bound(a.begin(), a.end(), n - a[i]);
            if (it != a.end())
            {
                int idx = it - a.begin();
                if (i == idx)
                {
                    idx++;
                }
                cout << "i " << i << " idx " << idx << endl;
                if (idx < m)
                {
                    sum += (pf[idx] - ((m - idx) * (n - 1 - a[i])));
                }
                if(i<idx){
                    sum -= (2 * (a[i] - n + 1));
                }
            }
        }
        cout << "sum " << sum << endl;
    }
}