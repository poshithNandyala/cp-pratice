#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> level(n);
    for (auto &p : level)
        cin >> p;
    sort(level.begin(), level.end());
    int ans = 1;
    vector<int> dif;
    for (int i = 1; i < n; i++)
        dif.push_back(level[i] - level[i - 1]);
    sort(dif.begin(), dif.end());

    for (int i = 0; i < dif.size(); i++)
    {
        if (dif[i] > x)
        {
            int temp = (dif[i] + x - 1) / x;
            temp--;
            if (k >= temp)
            {
                k -= temp;
            }
            else
                ans++;
        }
    }
    cout << ans << endl;
}
