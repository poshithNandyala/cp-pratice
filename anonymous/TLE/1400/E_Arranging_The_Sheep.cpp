#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> a(n+1);
        ll cnt = 0, dot = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                cnt++;
            }
            else
            {
               a[i]=1;
            }
          
        }
        for(ll i=1;i<=n;i++){
            a[i]+=a[i-1];
        }
        // for(ll i=0;i<=n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        ll ans1 = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                ans1++;
            }
            if (ans1 == ((cnt+1) / 2))
            {
                ans1 = i;
                break;
            }
        }
        ll ans=0;
        // cout<<"ans1"<<ans1<<endl;
        for(ll i=0;i<ans1;i++){
            if(s[i]=='*'){
                ans+=(a[ans1]-a[i]);
            }
        }
        for(ll i=ans1+1;i<n;i++){
            if(s[i]=='*'){
                ans+=(a[i]-a[ans1]);
            }
        }
        cout<<ans<<endl;
    }
}