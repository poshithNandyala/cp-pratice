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
        vector<ll> v(n), a, id, b;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] < (i + 1))
            {
                a.push_back(v[i]);
                id.push_back(i + 1);
            }
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        ll m = a.size();
        for (ll i = 0; i < m; i++)
        {
             auto it=upper_bound(a.begin(),a.end(),id[i]);
            if(it!=a.end()){
                ans+=a.end()-it;
            }
        }
        cout << ans << endl;
        // for(auto item : a){
        //     cout << item << " ";
        // }
        // cout << "\n";
        // for(auto item : id){
        //     cout << item << " ";
        // }
        // cout << "\n";
        // cout << endl;
    }
}