#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

bool is_prime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll next_prime(ll n)
{
    while (!is_prime(n))
    {
        n++;
    }
    return n;
}

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;

        ll p = next_prime(d + 1);
        ll q = next_prime(p + d);
        cout << min(p * p * p, p * q) << endl;
    }
}