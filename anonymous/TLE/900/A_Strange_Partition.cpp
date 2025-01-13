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
        ll x;
        ll min=0, max=0, sum=0;
        cin >> n >> x;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            max = max + ((a[i]+x-1) / x);
            sum += a[i];
        }
        min = (sum + x - 1) / x;
        cout << min << " " << max << endl;
    }
}