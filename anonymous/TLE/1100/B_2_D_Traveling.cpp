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
        ll n, k, a, b;
        cin >> n >> k >> a >> b;
        ll mia = LLONG_MAX, mib = LLONG_MAX;

        vector<pair<ll, ll>> v;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        ll ax = v[a - 1].first, ay = v[a - 1].second, bx = v[b - 1].first, by = v[b - 1].second;
        // cout<<"ax "<<ax<<"ay "<<ay<<"bx "<<bx<<"by "<<by<<endl;
        for (int i = 0; i < k; i++)
        {
            mia = min(mia, abs(ax - v[i].first) + abs(ay - v[i].second));
            mib = min(mib, abs(bx - v[i].first) + abs(by - v[i].second));
        }
        if (mia == LLONG_MAX && mib == LLONG_MAX)
        {
            mia = abs(ax - bx) + abs(ay - by);
            mib = 0;
        }
        cout << min(abs(ax - bx) + abs(ay - by), mia + mib) << endl;
    }
}
