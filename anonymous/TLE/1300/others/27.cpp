#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        sort(v.begin(), v.begin() + i + 1);
        int ans = 0;
        for (int j = i; j >= 0; j -= 2)
        {
            ans += v[j];
        }
        // cout<<ans<<" ";
        if (ans <= k)
        {
            res = i + 1;
        }
    }
    cout << res << "\n";
    return 0;
}
