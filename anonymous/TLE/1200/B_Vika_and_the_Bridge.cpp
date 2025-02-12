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
        vector<int> c(n);
        map<int, vector<int>> mp;
        for (int i = 1; i <= k; i++)
        {
            mp[i].push_back(0);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            mp[c[i]].push_back(i + 1);
        }
        for (int i = 1; i <= k; i++)
        {
            mp[i].push_back(n + 1);
        }
        // for (auto item : mp)
        // {
        //     for (auto item : item.second)
        //     {
        //         cout << item << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        int ans = (n / 2), tempans = 0, secondans = 0;
        for (auto i : mp)
        {
            tempans = 0;
            secondans = 0;
            for (int j = 1; j < i.second.size(); j++)
            {
                if (tempans <=( i.second[j] - i.second[j - 1] - 1))
                {
                    secondans = tempans;
                    tempans = i.second[j] - i.second[j - 1] - 1;
                }
                else if(secondans < (i.second[j] - i.second[j - 1] - 1))
                {
                    secondans = i.second[j] - i.second[j - 1] - 1;
                }
            }
            // cout << "tempans " << tempans << " secondans " << secondans << endl;
            ans = min(ans, max((tempans / 2), secondans));
        }
        cout << ans << endl;
        // cout<< endl;
    }
}