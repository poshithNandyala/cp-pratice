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
        ll n, k;
        cin >> n >> k;
        int m = 1000000007;
        ll ans = 1;
        for (int i = 0; i < k; i++)
        {
            ans = (ans * n) % m;
        }
        cout << ans << endl;
    }
}