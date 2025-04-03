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
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0)
            {
                a[i] += a[i - 1];
            }
        }
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     a[i] += a[i + 1];
        // }
        // for(auto item : a){
        //     cout << item << " ";
        // }
        // cout << "\n";
        // k *= n;
        ll lo = 1, hi = n * k, totalsum = (k * a[n - 1]);
        // if (k % n != 0)
        // {
        //     totalsum += a[(k % n) - 1];
        // }
        // cout << totalsum << endl;
        ll ans = 0;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            ll v = mid -1;
            ll sum = ((v / n) * a[n - 1]);
            // cout<<"sum1: "<<sum<<endl;
            if ((v % n) != 0)
            {
                sum += a[(v % n) - 1];
                // cout<<"sum2: "<<sum<<endl;
            }
            sum = totalsum - sum;
            // cout<<mid<<" "<<v<<" "<<sum<<endl;
            if (sum >= x)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << ans << endl;

    }
}
