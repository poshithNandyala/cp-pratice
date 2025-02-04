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
        ll a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n+1);
        for (int i = 1; i <= n; i++)
        {
            a[i] += a[i - 1];
        }
        // for(auto item : a){
        //     cout << item << " ";
        // }
        // cout << "\n";
        
        ll ans = 0;
        for (int i = 0; i <= k; i++)
        {
            int first = i * 2;
            int second = n - (k - i);
            // cout<<first<<" "<<second<<endl;
            ans = max(ans, a[second] - a[first]);
        }
        cout << ans << endl;
        // int ii = 0, j = n - 1;
        // while (k--)
        // {
        //     if (a[ii] + a[ii + 1] >= a[j])
        //     {
        //         j--;
        //     }
        //     else
        //     {
        //         ii += 2;
        //     }
        // }
     
        // for (int i = ii; i <= j; i++)
        // {
        //     ans += a[i];
        // }
        // cout << ans << endl;
    }
}
