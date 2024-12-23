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
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int ans =( n / (a + b + c))*3;
        int v = n % (a + b + c);
        // int x = a;
        // while(v>0){
        //     ans += 1;
        //     v -= x;
        //     if(x == a){
        //         x = b;
        //     }else if(x == b){
        //         x = c;
        //     }
        // }
        // cout<<ans<<endl;
        if(v == 0){
            cout<<ans<<endl;
        }else if(v <= a){
            cout<<ans+1<<endl;
        }else if(v <= a + b){
            cout<<ans+2<<endl;
        }else{
            cout<<ans+3<<endl;
        }
    }
}