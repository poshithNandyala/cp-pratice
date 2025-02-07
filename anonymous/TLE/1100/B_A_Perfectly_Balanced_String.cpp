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
        string s;
        cin >> s;
        int n = s.size();
        map<char, int> mp;
        int id = n;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            if (mp[s[i]] == 2)
            {
                id = i;
                break;
            }
        }
        bool ans = true;
        int j = 0;
        for (int i = id; i < n; i++)
        {
            if (s[i] != s[j % (id)])
            {
                ans = false;
                break;
            }
            j++;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}