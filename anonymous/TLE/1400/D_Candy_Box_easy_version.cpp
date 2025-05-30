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
        map<ll, ll> mp;
        vector<ll> a;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            mp[x]++;
        }
        for (auto it : mp)
        {
            a.push_back(it.second);
        }
        sort(a.begin(), a.end());
        ll sum = a[a.size() - 1];
        ll curr = sum;
        // for(auto item : a){
        //     cout << item << " ";
        // }
        // cout << "\n";
        
        for (int i = a.size() - 2; i >= 0; i--)
        {
            if (curr <= 0)
            {
                break;
            }
            if (a[i] >= curr)
            {
                sum += (curr - 1);
                curr--;
            }
            else
            {
                sum += a[i];
                curr = a[i];
            }
        }
        cout << sum << endl;
    }
}