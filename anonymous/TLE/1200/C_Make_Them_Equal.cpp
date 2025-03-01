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
        char c;
        cin >> c;
        string s;
        cin >> s;
        vector<int> v;
        vector<bool> f(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != c)
            {
                ans = i + 1;
                f[i] = true;
            }
        }
        bool an = false;
        int ans1 = 0;
        if (ans + 1 <= n)
        {
            an = true;
            ans1 = ans + 1;
        }
        if (!an)
        {
            for (int i = 1; i < n; i++)
            {
                int t = i + 1;
                if (!f[i])
                {
                    bool ans = true;
                    for (int j = t; j <= n; j += j)
                    {
                        if (f[j - 1])
                        {
                            ans = false;
                            break;
                        }
                    }
                    if (ans)
                    {
                        ans1 = t;
                        an = true;
                    }
                }
            }
        }
        if (ans1 == 1)
        {
            cout << 0 << endl;
        }
        else if (an)
        {
            cout << 1 << endl;
            cout << ans1 << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << n - 1 << " " << n << endl;
        }
    }
}