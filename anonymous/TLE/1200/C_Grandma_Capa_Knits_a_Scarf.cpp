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
        set<char> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(s[i]);
        }
        vector<int> ans(26, 1000000000);
        for (auto &a : st)
        {
            int l = 0;
            int r = n - 1;
            int c = 0;
            while (l < r)
            {
                if (s[l] == s[r])
                {
                    l++;
                    r--;
                }
                else
                {
                    if (s[l] == a)
                    {
                        l++;
                        c++;
                    }
                    else if (s[r] == a)
                    {
                        r--;
                        c++;
                    }
                    else
                    {
                        c = -2;
                        break;
                    }
                }
            }
            if (c != -2)
            {
                ans[a - 'a'] = c;
            }
        }
       sort(ans.begin(), ans.end());
        if (ans[0] == 1000000000)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans[0] << endl;
        }
    }
}