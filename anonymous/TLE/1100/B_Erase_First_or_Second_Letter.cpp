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
        string s;
        cin >> s;
        map<char, int> mp;
        ll ans = 1;
        mp[s[0]]++;
        for (int i = 1; i < n; i++)
        {
            mp[s[i]]++;
            ans += mp.size();
        }
        cout << ans << endl;
    }
}