#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio
        ll n,
        k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> v;
    ll ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > x)
        {
            ans++;
            
                v.push_back((a[i] - a[i - 1] - 1) / x);
        }
    }
    // for(auto item : a){
    //     cout << item << " ";
    // }
    // cout << "\n";

    sort(v.begin(), v.end());
    // for(auto item : v){
    //     cout << item << " ";
    // }
    // cout << "\n";

    int i = 0;
    while ((k > 0) && (i < v.size()))
    {
        k -= v[i];
        if (k >= 0)
        {
            ans--;
        }
        i++;
    }
    cout << ans << endl;
}