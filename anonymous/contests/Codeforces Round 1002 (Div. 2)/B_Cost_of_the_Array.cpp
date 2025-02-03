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
        cin >> n >> k;
        int a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (k != n)
        {
            bool ans = true;
            for (int i = 2; i <= n - k + 2; i++)
            {
                if (a[i] != 1)
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
        else
        {
            vector<int> v;
            for (int i = 2; i <= n; i += 2)
            {
                v.push_back(a[i]);
            }
            v.push_back(0);
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] != i + 1)
                {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
}