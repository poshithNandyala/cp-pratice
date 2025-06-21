#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<li> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        vector<li> sum(n + 1);
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + b[i];
        vector<li> cnt(n + 1), add(n + 1);
        for (int i = 0; i < n; ++i)
        {
            int j = upper_bound(sum.begin(), sum.end(), a[i] + sum[i]) - sum.begin() - 1;
            cnt[i] += 1;
            cnt[j] -= 1;
            add[j] += a[i] - sum[j] + sum[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cout << cnt[i] * b[i] + add[i] << ' ';
            cnt[i + 1] += cnt[i];
        }
        cout << '\n';
    }
}