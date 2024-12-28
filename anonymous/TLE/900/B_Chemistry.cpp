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
        string s;
        cin >> n >> k >> s;
        map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        int ans = 0;
        for (auto i : mp)
        {
            ans += i.second % 2;
        }
        // cout << "ans" << " " << ans << endl;
        if (k >= ans-1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}