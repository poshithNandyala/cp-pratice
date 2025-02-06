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
        ll a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll r[n + 1]={}, l[n + 1]={},sum=0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            l[i] = sum;
        }
        sum = 0;
        for (int i = n; i >= 1;i--){
            sum += a[i];
            r[i] = sum;
        }
        ll gcd = 0;
        for (int i = 1; i < n; i++)
        {
            gcd = max(gcd,__gcd(l[i],r[i+1]));
        }
        cout << gcd << endl;
    }
}