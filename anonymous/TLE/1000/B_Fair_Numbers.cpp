#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

bool isFair(ll n)
{
    ll temp = n;
    while (n > 0)
    {
        ll digit = n % 10;
        if (digit && temp % digit)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}
int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        while (!isFair(n))
        {
            n++;
        }
        cout << n << endl;
    }
}