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
        ll a[n + 1], b[n + 1];
        map<ll, ll> mpa, mpb;
        // map<ll, bool> bs;
        // cout << endl;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        ll c = 1;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] == a[i - 1])
            {
                c++;
            }
            else
            {
                mpa[a[i - 1]] = max(mpa[a[i - 1]], c);
                c = 1;
            }
        }
        mpa[a[n]] = max(mpa[a[n]], c);
        c = 1;
        for (int i = 2; i <= n; i++)
        {
            if (b[i] == b[i - 1])
            {
                c++;
            }
            else
            {
                // cout << b[i - 1] << " " << c << endl;
                mpb[b[i - 1]] = max(mpb[b[i - 1]], c);
                c = 1;
            }
        }
        mpb[b[n]] = max(mpb[b[n]], c);

        for (auto i : mpa)
        {
            auto x = mpb.find(i.first);
            if (x != mpb.end())
            {
                ans = max(ans, i.second + x->second);
            }
            else
            {
                ans = max(ans, i.second);
            }
        }
        for (auto i : mpb)
        {
            auto x = mpa.find(i.first);
            if (x != mpa.end())
            {
                ans = max(ans, i.second + x->second);
            }
            else
            {
                ans = max(ans, i.second);
            }
        }
        // for(auto item : mpa){
        //     cout << item.first << " " << item.second << " ";
        // }
        // cout << "\n";
        // for(auto item : mpb){
        //     cout << item.first << " " << item.second << " ";
        // }
        // cout << "\n";
        
        cout << ans << endl;
    }
}