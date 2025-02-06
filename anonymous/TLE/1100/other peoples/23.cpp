#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, l, r;
    cin >> n >> l >> r;
    vector<long long> ans;
    for (long long i = 1; i <= n; i++)
    {
        long long k = 1ll * (l + i - 1) / i;
        if (k * i <= r)
            ans.push_back(k * i);
        else
            break;
    }
    if (ans.size() != n)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}