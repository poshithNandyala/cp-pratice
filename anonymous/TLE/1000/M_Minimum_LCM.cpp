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
        ll n;
        cin >> n;
        ll ans = n, a, b, aa = 1, bb = n-1, sq = sqrt(n);
        if (n % 2 == 0)
        {
            aa = n / 2;
            bb = n / 2;
            ans = aa;
        }
        for (ll i = 2; i <= sq; i++)
        {
            if (n % i == 0)
            {
                a = i;
                b = n - i;
                // cout<<a
                if (ans > ((a * b) / __gcd(a, b)))
                {
                    aa = a;
                    bb = b;
                    ans = (a * b) / __gcd(a, b);
                }
                a = n / i;
                b = n - a;
                if (ans > ((a * b) / __gcd(a, b)))
                {
                    aa = a;
                    bb = b;
                    ans = (a * b) / __gcd(a, b);
                }
            }
        }
        cout << aa << " " << bb << endl;
    }
}
