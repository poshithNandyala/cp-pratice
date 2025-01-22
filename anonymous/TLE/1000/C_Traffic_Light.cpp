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
        int n, ans = 1;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;
        if (c == 'g')
        {
            ans = 0;
        }
        if (ans)
        {
            int cn = 0, st = -1;
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                // cout << "cns" << cn << endl;
                if (cn == 0 && s[i] == c)
                {
                    cn++;
                    flag = true;
                }

                else if (s[i] == 'g' && st == -1)
                {
                    st = i;
                    ans = max(ans, cn);
                    cn = 0;
                    flag = false;
                }
                else if (s[i] == 'g' && cn)
                {
                    ans = max(ans, cn);
                    cn = 0;
                    flag = false;
                }
                else if (flag)
                {
                    cn++;
                }
                // cout << "cne" << cn << endl;
            }
            // cout << "st" << st << "cn" << cn << endl;
            if (cn)
            {
                ans = max(ans, cn + st);
            }
        }
        cout << ans << endl;
    }
}