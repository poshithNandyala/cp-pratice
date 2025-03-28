#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100001;
ll n, k;
ll arr[N];
map<ll, ll> freq;
bool check(ll minVal)
{
    ll totalUsefulBalls = 0;
    for (auto v : freq)
    {
        totalUsefulBalls += min(v.second, minVal);
    }
    return totalUsefulBalls >= k * minVal;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcases;
    cin >> testcases;
    while (testcases--)
    {
        cin >> n >> k;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        ll low = 0, high = n;
        ll ans = low;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (check(mid))
                ans = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        cout << ans << "\n";
        freq.clear();
    }
}
