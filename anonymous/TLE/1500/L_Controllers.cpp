#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio ll n;
    cin >> n;
    string s;
    cin >> s;
    ll plus = 0, minus = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
            minus++;
        else
            plus++;
    }
    if (plus < minus)
    {
        swap(plus, minus);
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if (a < b)
        {
            swap(a, b);
        }
        ll tot = plus - minus;
        if (tot == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        if (a == b)
        {
            cout << "NO" << endl;
            continue;
        }
        ll y = a, x = b;
        if ((tot * y) % (y - x) != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        ll k = (tot * y) / (y - x);
        if (k >= -minus && k <= plus)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}