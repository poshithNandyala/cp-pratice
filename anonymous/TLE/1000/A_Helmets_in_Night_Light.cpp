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
        int n, p;
        cin >> n >> p;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        int x = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[x].second == 0)
            {
                x++;
            }
            a[x].second--;
            ans += min(a[x].first, p);
        }
        cout << ans+p << endl;
    }
}