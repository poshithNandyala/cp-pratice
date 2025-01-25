#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);

int main(){
    fastio
    vector<int> aa(3000001);
    aa[0] = 0;
    for (int i = 1;i < 3000001;i++){
        aa[i] = aa[i-1] ^ i;
    }
    int t;
    cin >> t;
    while(t--){
        int a, b;   
        cin >> a >> b;
        int x = aa[a-1],ans=a;
        if(x!=b){
            x ^= b;
            if(x==a){
                ans+=2;
            }
            else{
                ans++;
            }
            
        }
        cout << ans << endl;
    }
}