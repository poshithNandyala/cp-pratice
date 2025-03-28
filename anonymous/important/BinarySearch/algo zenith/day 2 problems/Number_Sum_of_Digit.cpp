// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, s;
bool check(ll x)
{
    ll digitSum = 0;
    ll k = x;
    while (k > 0)
    {
        digitSum += (k % 10);
        k /= 10;
    }
    return abs(digitSum - x) >= s;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        ll low = 1, high = n;
        ll ans = n+1;
        while (low <= high)
        {
            ll mid = (low + ((high - low) / 2));
            if (check(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << n - ans + 1 << '\n';
    }
}