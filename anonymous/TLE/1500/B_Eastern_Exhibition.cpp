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
        vector<int> xx, yy;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            xx.push_back(x);
            yy.push_back(y);
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        cout << (xx[n / 2] - xx[(n - 1) / 2] + 1) * 1LL * (yy[n / 2] - yy[(n - 1) / 2] + 1) << endl;
    }
}