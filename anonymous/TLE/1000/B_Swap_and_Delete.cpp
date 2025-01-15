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
        int one = 0, zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        int mi = min(one, zero);
        int mx = max(one, zero);
        int ans = mx - mi;
        one = mi;
        zero = mi;
        if (ans)
        {
            int m = 2 * mi;
            int ones = 0, zeroes = 0;
            int x = 0;
            for (int i = 0; i < m; i++)
            {
                if (s[i] == '1' && zero>0)
                {
                    zero--;
                    x++;
                }
                else if(one>0 && s[i] == '0')
                {
                    one--;
                    x++;
                }
                else{
                    break;
                }
            
            }
            ans+=(m-x);
        }
        cout << ans << endl;
    }
}