#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        int n,x;
        cin >> n >> x;
        int ma=n,mi=(1ll<<62);
        int mask=0;
        for(int i=0;i<61;i=i+1){
            if(((n>>i)&1)==0){
                if(((x>>i)&1)==1){
                    mi=-1;
                    break;
                }
            } else {
                int now=n+(1ll<<i)-(n&mask);
                if(((x>>i)&1)==1){
                    mi=min(mi,now);
                } else {
                    ma=max(ma,now);
                }
            }
            mask=mask+(1ll<<i);
        }
        if(ma<mi) cout<<ma<<endl;
        else cout<<-1<<endl;
    }
}
