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
        int n;
        cin >> n;
        ll x;
        cin >> x;
        for (int i = 0; i < n - 1; i++)
        {
            ll a;
            cin >> a;
            x &= a;
        }
        cout << x << endl;
    }
}