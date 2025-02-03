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
        ll n, q;
        cin >> n >> q;
        ll aa[n];
        vector<int> s;
        s.push_back(31);
        
        for (int i = 0; i < n; i++)
        {
            cin >> aa[i];
        }
        
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            if (x < s.back()) {
                s.push_back(x);
            }
        }
        
        for (ll x : aa)
        {
            for (int y : s)
            {
                if (x % (1 << y) == 0)
                {
                    x |= 1 << (y - 1);
                }
            }
            cout << x << " ";
        }
        cout << "\n";
    }
}