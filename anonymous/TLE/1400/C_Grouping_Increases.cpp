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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int aa = a[0], bb = 0;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > max(aa, bb))
            {
                if (bb == 0)
                {
                    ans--;
                    bb = a[i];
                }
                else if (aa > bb)
                {
                    bb = a[i];
                }
                else
                {
                    aa = a[i];
                }
                ans++;
            }
            else if (a[i] <= min(aa, bb))
            {
                if (aa > bb)
                {
                    bb = a[i];
                }
                else
                {
                    aa = a[i];
                }
            }
            else
            {
                if (aa >= a[i])
                {
                    aa = a[i];
                }
                else
                {
                    bb = a[i];
                }
            }
            // cout << aa << " " << bb << endl;
        }
        // cout << aa << " " << bb << endl;
        cout << ans << endl;
    }
}