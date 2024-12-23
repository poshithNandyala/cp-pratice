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
        int n, m, k;
        cin >> n >> m >> k;
        int a[m],q[k];
        for(int i = 0; i < m; i++){
            cin >> a[i];
        }
        int value = -1;
        for(int i = 0; i < k; i++){
            cin >> q[i];
            if(i>0 && q[i] - q[i-1] > 1){
                value = q[i-1]+1;
            }
        }
        if(value == -1){
            if(q[0] == 1){
                value = n;
            }
            else{
                value = 1;
            }
        }
        if(k<(n-1)){
            for (int i = 0;i<m;i++){
                cout << 0;
            }
        }
        else if(k==(n-1)){
            for(int i = 0; i < m; i++){
                if(a[i]==value){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }
        }
        else{
            for (int i = 0; i < m; i++)
            {
                cout << 1;
            }
        }
        cout << endl;
    }
}