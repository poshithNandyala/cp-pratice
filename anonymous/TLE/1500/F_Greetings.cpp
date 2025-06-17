#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

// Fenwick Tree for prefix sums
struct Fenwick
{
    ll N;
    vector<ll> bit;
    Fenwick(ll n) : N(n), bit(n + 1, 0) {}

    void update(ll i, ll v = 1)
    {
        for (; i <= N; i += i & -i)
            bit[i] += v;
    }

    ll query(ll i) const
    {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<pair<ll, ll>> v(n);
        for (ll i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            v[i] = {x, y};
        }

        sort(v.begin(), v.end());

        // Build array from second elements
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            a[i] = v[i].second;

        // Coordinate compression
        vector<ll> comp = a;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        auto rank_of = [&](ll x)
        {
            return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1; // 1-based
        };

        // Fenwick tree and answer array
        Fenwick fw(comp.size());
        vector<ll> ans(n);

        for (ll i = n - 1; i >= 0; --i)
        {
            ll r = rank_of(a[i]);
            ans[i] = fw.query(r); // how many values <= a[i] to the right
            fw.update(r, 1);
        }
        cout<<accumulate(ans.begin(), ans.end(), 0LL) << endl;
    }

    return 0;
}
