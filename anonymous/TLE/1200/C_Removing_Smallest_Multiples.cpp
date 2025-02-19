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
        int j = 0;
        ll ans = 0;
        bool ok;

        for (int i = 1; i <= n; i++)
        {
            j = i - 1;
            // ok = true;
            while ((j < n) && ((s[j] == '0') || ((s[j] == '2'))))
            {
                if (s[j] == '0')
                {
                    s[j] = '2';
                    // cout << "i " << i << " j " << j << " ans " << ans << endl;
                    ans += i;
                    // cout << "ans " << ans << endl;
                    // cout << s << endl;
                    // ok = false;
                }
                j += i;
            }
        }
        cout << ans << endl;
    }
}