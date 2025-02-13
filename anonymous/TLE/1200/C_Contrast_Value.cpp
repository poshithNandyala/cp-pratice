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
    // int k = 0;
    while (t--)
    {
        // k++;
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        // if (k == 153)
        // {
        //     cout << n << "n";
        //     for (int i = 0; i < n; i++)
        //     {
        //         cout << a[i] << "a";
        //     }
        //     cout << endl;
        // }

        int ans = 1;
        int i = 1;
        for (i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
            {
                break;
            }
        }
        int c = 0;
        for (; i < n;)
        {
            c = 0;
            while (i < n)
            {
                if (a[i] >= a[i - 1])
                {
                    c++;
                    i++;
                }
                else
                {
                    if (c)
                    {
                        ans++;
                    }
                    // cout << "i1 " << i <<"c"<<c<< "ans" << ans << endl;
                    break;
                }
            }
            c = 0;
            while (i < n)
            {
                if (a[i] <= a[i - 1])
                {
                    i++;
                    c++;
                }
                else
                {
                    if (c)
                    {
                        ans++;
                    }
                    // cout << "i2 " << i << "c" << c << "ans" << ans << endl;
                    // cout << "i " << " " << i << endl;
                    break;
                }
            }
        }
        if (mp.size() == 1)
        {
            ans = 0;
        }
        cout << ans + 1 << endl;
    }
}