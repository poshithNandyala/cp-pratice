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
        vector<int> a(n);
        vector<int> even, odd;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                even.push_back(a[i]);
            }
            else
            {
                odd.push_back(a[i]);
            }
        }
        ll ans1 = -1, ans2 = -1;
        if (even.size() > 0)
        {
            ans1 = even[even.size() - 1];
        }
        if (odd.size() > 0)
        {
            ans2 = odd[odd.size() - 1];
        }

        if (ans1 != -1)
        {
            ll temp = ans1;
            even.pop_back();
            if (odd.size())
            {
                ll temp1 = 0;
                temp1 = odd[odd.size() - 1];
                ans1 += odd[odd.size() - 1];
                odd.pop_back();
                for(auto i:even)
                {
                    ans1 += i;
                }
                for(auto i:odd)
                {
                    ans1 += (i - 1);
                }
                odd.push_back(temp1);
            }
            even.push_back(temp);
        }
        if (ans2 != -1)
        {
            odd.pop_back();
            if (even.size())
            {
                for(auto i : even)
                {
                    ans2 += i;
                }
                for(auto i : odd)
                {
                    ans2 += (i - 1);
                }
            }
        }
        // cout << ans1 << " " << ans2 << endl;
        cout << max(ans1, ans2) << endl;
    }
}