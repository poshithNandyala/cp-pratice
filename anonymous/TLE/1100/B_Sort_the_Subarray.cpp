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
        int n;
        cin >> n;
        int a[n],b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        int s = 0, e = n-1;
        for(int i = 0; i < n; i++){
            if(a[i]!=b[i]){
                s = i;
                break;
            }
        }
        // cout << s << " " << e << endl;
        for(int i = n-1; i >= 0; i--){
            if(a[i]!=b[i]){
                e = i;
                break;
            }
        }
        for (int i = s;i>0;i--){
            if(b[i]>=b[i-1]){
                s = i-1;
            }
            else{
                break;
            }
        }
        for (int i = e;i<n-1;i++){
            if(b[i]<=b[i+1]){
                e = i+1;
            }
            else{
                break;
            }
        }
        cout<<s+1<<" "<<e+1<<endl;
    }
}