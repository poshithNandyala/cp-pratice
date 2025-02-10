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
        ll n, x, y;
        cin >> n >> x >> y;
        ll lcm = (x * y) / (__gcd(x, y));
        ll xx = ((n / x) - (n / lcm)), yy = ((n / y) - (n / lcm));
        xx = n - xx;
        ll ans = (n*(n+1))/2 - (xx*(xx+1))/2 - (yy*(yy+1))/2;
        cout << ans << endl;
    }
}