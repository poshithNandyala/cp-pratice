#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

ll lowerbound(vector<ll> &a, ll x, ll i)
{
    ll n = a.size();
    ll l = 0, r = n - 1;
    ll ans = n;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (a[mid] - ((n - mid) * i) >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 1; i < n; i++)
        {
            a[i] += a[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            a[i] *= -1;
        }
        sort(a.begin(), a.end());
        // for (auto item : a)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";
        x *= -1;
        // cout << "x = " << x << endl;
        int i = 0;
        while (true)
        {
            ll lower = lowerbound(a, x, i);
            // cout << lower << " ";
            if (lower == n)
            {
                break;
            }
            else
            {
                ans += n - lower;
            }
            i++;
        }
        // cout << endl;
        // cout << "ans ";
        cout << ans << endl;
        // cout << "\n";
    }
}