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
        map<int, int> mp;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        for (auto it : mp)
        {
            a.push_back(it.second);
        }
        n = a.size();
        sort(a.begin(), a.end());
        int ans = -1, i = 0;
        while (k >= 0)
        {

            ans++;
            k -= a[i];
            i++;
            if (i == n)
            {
                break;
            }
        }
        cout << n - ans << endl;
    }
}