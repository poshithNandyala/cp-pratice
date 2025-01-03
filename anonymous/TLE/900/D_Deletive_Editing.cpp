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
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        map<char, int> mp[n], mpt;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                mp[j][s[i]]++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            mpt[t[i]]++;
        }
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (mp[n - 1][t[i]] >= mpt[t[i]])
            {
                continue;
            }
            else
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            string temp = "";
            for (int i = n - 1; i >= 0; i--)
            {
                if (mpt[s[i]] > 0)
                {
                    temp += s[i];
                    mpt[s[i]]--;
                }
            }
            reverse(temp.begin(), temp.end());
            cout << temp << endl;
            if(temp!= t)
            {
                ans = false;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}