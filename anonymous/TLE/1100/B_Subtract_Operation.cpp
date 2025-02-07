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
        ll a[n];
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            ll x = a[i] + k;
            if (binary_search(a + i + 1, a + n, x))
            {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}