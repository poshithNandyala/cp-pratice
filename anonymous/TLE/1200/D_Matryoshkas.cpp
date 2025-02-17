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
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        ll ans = mp.begin()->second, sum = mp.begin()->second, x = (mp.begin()->first) + 1;
        // cout << "sum " << sum << "ans" << ans << endl;
        int k = 0;
        for (auto it = ++mp.begin(); it != mp.end(); it++)
        {
            if ((it->first == x) && (it->second >= sum))
            {
                k = (it->second) - sum;
                // cout << "k " << k << endl;
                ans += k;
                sum += k;
                x++;
            }
            else if (it->first != x)
            {
                sum = it->second;
                ans += it->second;
                x = it->first + 1;
            }
            else if (it->second < sum)
            {
                sum = it->second;
                x++;
            }
            // cout<<it->first<<" "<<it->second<<endl;
            // cout << "sum " << sum << "ans" << ans << endl;
        }
        cout << ans << endl;
    }
}