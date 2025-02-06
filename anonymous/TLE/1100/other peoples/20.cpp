#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        ll sum = 0, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i, sum += i;
        for (ll tmp = a[0], i = 0; i < n - 1; i++, tmp += a[i])
            ans = max(ans, __gcd(tmp, sum - tmp));
        cout << ans << '\n';
    }
}