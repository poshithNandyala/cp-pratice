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
        vector<ll> a(n);
        vector<ll> m(31, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            for (int j = 0; j < 31; j++)
            {
                if ((a[i] & (1 << j)))
                {
                    m[j]++;
                }
            }
        }
        // for(auto item : m){
        //     cout << item << " ";
        // }
        // cout << "\n";
        
        for (ll i = 1; i <= n; i++)
        {
            bool ans = true;
            for (ll j = 30; j >= 0; j--)
            {
                if (m[j]%i)
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}