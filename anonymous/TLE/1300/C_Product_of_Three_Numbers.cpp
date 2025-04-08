#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

int main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a=-1, b=-1, c=-1;
        bool ans = false;
        for(ll i=2; i*i<=n; i++){
            if(n%i==0){
                a = i;
                ll x=n/i;
                for(ll j=2; j*j<=x; j++){
                    if(x%j==0  && j!=x/j && j!=a && x/j!=a){
                        b = j;
                        c = x/j;
                        ans = true;
                        break;
                    }
                }
                if(ans) break;
                a = n / i;
                x = i;
                for (ll j = 2; j * j <= x; j++)
                {
                    if (x % j == 0 && j != x / j && j != a && x / j != a)
                    {
                        b = j;
                        c = x / j;
                        ans = true;
                        break;
                    }
                }
            }
            if(ans) break;
        }
        if(ans){
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}