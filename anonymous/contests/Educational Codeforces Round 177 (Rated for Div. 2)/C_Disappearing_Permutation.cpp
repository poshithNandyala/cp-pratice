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
        vector<int> a(n + 1);
        vector<int> b(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int k = n;
        int ans = 0;
        while (k--)
        {
            int x;
            cin >> x;
            if (a[x] == x && b[x] == 0)
            {
                ans++;
                b[x] = 1;
            }
            else if (b[x] == 0)
            {
                int k = x;
                while (b[k] == 0)
                {
                    b[k] = 1;
                    k = a[k];
                    ans++;
                }
            }
            cout<<ans<<" ";
        }
        cout << endl;
    }
}