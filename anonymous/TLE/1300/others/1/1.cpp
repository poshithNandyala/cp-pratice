// D. Divisible Pairs
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, x, y;
int a[N];
void solve()
{
    // Map to store frequency of remainder pairs (mod x, mod y)
    map<pair<int, int>, int> f;
    cin >> n >> x >> y;
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        // Calculate remainders when divided by x and y
        int v1 = a[i] % x, v2 = a[i] % y;
        // For current number a[i], find count of previous numbers a[j] where:
        // (a[i] + a[j]) % x = 0 and (a[i] - a[j]) % y = 0
        // This means we need a[j] with remainder (x - v1) % x for sum divisibility
        // and same v2 remainder for difference divisibility
        res += f[{(x - v1) % x, v2}];
        // Store current number's remainder pair
        f[{v1, v2}]++;
    }
    cout << res << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}