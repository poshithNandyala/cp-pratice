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
        ll n;
        cin >> n;
        vector<ll> u(n), s(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> u[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        map<ll, vector<ll>> mp;

        for (ll i = 0; i < n; i++)
        {
            mp[u[i]].push_back(s[i]);
        }
        for (auto &it : mp)
        {
            sort(it.second.begin(), it.second.end(), greater<int>());
        }
        for (auto &it : mp)
        {
            for (ll i = 1; i < it.second.size(); i++)
            {
                it.second[i] += it.second[i - 1];
            }
        }
        // for(auto item : mp){
        //     for(auto item : item.second){
        //         cout << item << " ";
        //     }
        //     cout << "\n";

        // }
        // cout << "\n";
        // map<ll,ll> ans,sum;
        vector<ll> res(n+1);
        for (auto &it : mp)
        {
            for (ll i = 1; i <= it.second.size(); i++)
            {
                ll g = it.second.size() / i;
                if (g > 0)
                {
                    res[i] += it.second[g * i -1];
                }
            }
        }

        // ll i = 1;
        // for (i = 1; i <= n; i++)
        // {
        //     ll sum = 0;
        //     for (auto it : mp)
        //     {
        //         if (i <= it.second.size())
        //         {
        //             sum += it.second[it.second.size() - 1 - ((it.second.size()) % i)];
        //         }
        //     }
        //     if (sum == 0)
        //     {
        //         break;
        //     }
        //     cout << sum << " ";
        // }
        // for (; i <= n; i++)
        // {
        //     cout << 0 << " ";
        // }
        // cout << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }
        cout<<endl;
    }
}