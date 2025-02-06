#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int binexp(int a, int b, int m)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (1LL * res * a) % m;
        }
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        const int m = 1000000007;
        int n;
        cin >> n;
        ll ans = 0;
        int inverse = binexp(6, m - 2, m);
        ans = (1LL * n * (n + 1)) % m;
        ans = (ans * ((4LL * n - 1) % m)) % m;
        ans = (ans * 2022) % m;
        ans = (ans * inverse) % m;
        cout << ans << endl;
    }
}