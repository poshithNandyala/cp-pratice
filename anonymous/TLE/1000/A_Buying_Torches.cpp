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
        ll x, y, k;
        cin >> x >> y >> k;
        ll sticks = 1, ans = 0;
        sticks -= (k * y);
        ans += k;
        ll need = k;
        need -= sticks;
        x -= 1;
        ans += (need + x - 1) / x;
        cout << ans << endl;
    }
}