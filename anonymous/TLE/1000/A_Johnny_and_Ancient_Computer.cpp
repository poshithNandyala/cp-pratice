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
        ll a, b;
        cin >> a >> b;
        if (b < a)
        {
            swap(a, b);
        }
        // cout << "a = " << a << " b = " << b <<  endl;
        ll x = b / a;
        bool ans = false;
        if ((b % a) == 0 && (__builtin_popcountll(x) == 1))
        {
            ans = true;
        }

        if (ans)
        {
            ll x = b / a;
            ll ct = 0;
            while (x >= 1)
            {
                if (x >= 8)
                {
                    x /= 8;
                    ct++;
                }
                else if (x >= 4)
                {
                    x /= 4;
                    ct++;
                }
                else if (x >= 2)
                {
                    x /= 2;
                    ct++;
                }
                else
                {
                    break;
                }
            }
            cout << ct << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}