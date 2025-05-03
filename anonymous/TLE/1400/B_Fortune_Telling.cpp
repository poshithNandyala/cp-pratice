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
        ll odd = 0;
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            if (a % 2 == 1)
                odd++;
        }
        if ((odd % 2) ^ (x % 2 == y % 2))
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
}