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

        int n, s, sum = 0;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum < s)
        {
            cout << -1 << endl;
        }
        else if (sum == s)
        {
            cout << 0 << endl;
        }
        else
        {
            vector<int> f, b;
            f.push_back(0);
            b.push_back(0);
            int c = 1, j = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 1)
                {
                    f.push_back(c + f[j]);
                    j++;
                    c = 1;
                }
                else
                {
                    c++;
                }
            }
            c = 1;
            j = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 1)
                {
                    b.push_back(c + b[j]);
                    j++;
                    c = 1;
                }
                else
                {
                    c++;
                }
            }
            s = sum - s;
            int ans = INT_MAX;
            for (int i = 0; i <= s; i++)
            {
                ans = min(ans, f[i] + b[s - i]);
            }
            cout << ans << endl;
        }
    }
}
