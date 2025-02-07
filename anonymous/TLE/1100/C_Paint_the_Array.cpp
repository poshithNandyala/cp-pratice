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
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll gcd = 0;
        bool ans = true;
        for (int i = 1; i < n; i += 2)
        {
            gcd = __gcd(gcd, v[i]);
        }
        for (int i = 0; i < n; i += 2)
        {
            if ((v[i] % gcd)==0)
            {
                ans = false;
                break;
            }
        }
        if(!ans){
            gcd = 0;
            ans = true;
            for (int i = 0; i < n; i += 2)
            {
                gcd = __gcd(gcd, v[i]);
            }
            for (int i = 1; i < n; i += 2)
            {
                if ((v[i] % gcd)==0)
                {
                    ans = false;
                    break;
                }
            }
        }
        cout << (ans ? gcd : 0) << endl;
    }
}