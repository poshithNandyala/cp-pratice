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
        ll n,m;
        cin >> n >> m;
        ll ans=n;
        ll z=0;
        while(ans>0 && ans%10 == 0){
            ans/=10;
            z++;
        }
        ll k=1;
        while(ans >0 && ans%5 == 0){
            ans/=5;
            if(k*2 <= m){
                k*=2;
            }
            else{
               break;
            }
        }
        while(ans >0 && ans%2 == 0){
            ans/=2;
            if(k*5 <= m){
                k*=5;
            }
            else{
                break;
            }
        }
        while(k*10 <= m){
            k*=10;
        }
        k  =  (m/k)*k;
        if(!z && k==1){
            cout<<n*m<<endl;
        }
        else{
            cout<<n*k<<endl;
        }

    }
}