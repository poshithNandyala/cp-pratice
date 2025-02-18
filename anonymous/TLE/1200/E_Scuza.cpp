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
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n), mx(n), psum(n);
        cin >> a[0];
        mx[0] = a[0];
        psum[0] = a[0];
        for (ll i = 1; i < n; i++)
        {
            cin >> a[i];
            mx[i] = max(mx[i - 1], a[i]);
            psum[i] = psum[i - 1] + a[i];
        }
        // cout << (ll)(mx.end() - mx.begin()) << endl;

        // for (auto item : mx)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";
        // for (auto item : psum)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";


        while (q--)
        {
            int k;
            cin >> k;

            ll v = ((upper_bound(mx.begin(), mx.end(), k) - mx.begin()))-1;
            if (v == -1)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << psum[v] << " ";
            }
        }
        cout << endl;
    }
}