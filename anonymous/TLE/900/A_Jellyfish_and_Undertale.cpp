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
        ll a, b, n;
        cin >> a >> b >> n;
        ll ans = b;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if(x>=a){
                ans += (a-1);
            }
            else{
                ans += x;
            }
        }
        cout << ans << endl;
    }
}