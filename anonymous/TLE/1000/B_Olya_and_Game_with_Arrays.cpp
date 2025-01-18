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
        int mi1 = INT_MAX, mi2 = INT_MAX;
        ll sum = 0;
        vector<multiset<int>> a(n);
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                a[i].insert(x);
            }

            auto it = a[i].begin();
            if (a[i].size() == 1)
            {
                int y = *it;
                mi2 = min(mi2, y);
                sum += y;
            }
            else
            {
                int x = *(it);
                ++it;
                int y = *(it);
                mi1 = min(mi1, x);
                mi2 = min(mi2, y);
                sum += y;
            }
        }
        cout << sum - mi2 + mi1 << endl;
    }
}