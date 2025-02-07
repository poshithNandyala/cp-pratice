#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio

        int n,
        q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = n; i >= 1; i--)
    {
        mp[a[i]] = i;
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << mp[x] << " ";
        for (auto i : mp)
        {
            if (i.second < mp[x])
            {
                mp[i.first]++;
            }
        }
        mp[x] = 1;
    }
}
