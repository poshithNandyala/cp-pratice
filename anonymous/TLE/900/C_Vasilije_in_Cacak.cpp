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
        ll n, k, x;
        cin >> n >> k >> x;
        ll mi = (k * (k + 1)) / 2;
        ll ma = (n * (n + 1) / 2) - (((n - k) * (n - k + 1)) / 2);
        if (mi <= x && x <= ma)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}