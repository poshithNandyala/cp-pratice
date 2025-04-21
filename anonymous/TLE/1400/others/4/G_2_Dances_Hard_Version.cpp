#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

ll solve(vector<ll> a, vector<ll> b, ll n)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // for(auto item : a){
    //     cout << item << " ";
    // }
    // cout << "\n";
    
    // for(auto item : b){
    //     cout << item << " ";
    // }
    // cout << "\n";
    
    ll i = 0, j = 0;
    ll ans = 0;
    while (i < n && j < n)
    {
        if (a[i] < b[j])
        {
            i++;
            j++;
        }
        else
        {
            ans++;
            j++;
        }
    }
    return ans;
}

int main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        a[0] = 1;
        ll curr = solve(a, b, n);
        ll low = 1, high = m, temp = m + 1;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            // ll mid = low++;
            a[0] = mid;
            ll ans = solve(a, b, n);
            // cout<<"ans: "<<ans<<endl;
            if (ans > curr)
            {
                temp = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // cout << temp << endl;
        ll ans = (curr * m) + m - temp + 1;
        cout << ans << endl;
    }
}