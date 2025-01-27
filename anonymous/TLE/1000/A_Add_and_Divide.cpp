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
        int a, b;
        cin >> a >> b;
        int ans = 1;
        if(a>=b){
            ans = 31;
            int c = 0;
            for (int i = 0;i<=30;i++){
                int c = i;
                if(b+i>=2){
                    int x = a;
                    int y = b+i;
                    int cnt = i;
                    while(x>0){
                        x = x/y;
                        cnt++;
                    }
                    ans = min(ans, cnt);
                }
            }
        }
        cout << ans << endl;
    }
}