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
        int ans = 1 << 30;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            int k = ans;
            for (int j = 30; j >= 0; j--)
            {
                if (x >= k)
                {
                    mp[j]++;
                    break;
                }
                k /= 2;
            }        
        }
        ll ans1 = 0;
        for (auto i : mp)
        {
            ans1 += (i.second *1LL* (i.second - 1)) / 2;
        }
        cout << ans1 << endl;
    }
}