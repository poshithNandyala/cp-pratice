#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    fastio
    int t;
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n),b(n);
        b[0]=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i>=1 && a[i-1]>=2*a[i]){
                b[i]=1; 
            }        
        }
        for(int i=0;i<n;i++){
            b[i]+=b[i-1];
        }
        ll ans=0;
        for(int i=0;i<n-k;i++){
              if(!(b[i+k]-b[i])){
                ans++;
              }
        }
        cout<<ans<<endl;

    }
}