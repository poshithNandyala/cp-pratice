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
        if(n==4 || n==6){
            cout << 1 << " " << 1 << endl;
        }
        else{
            bool ans = true;
            if(n<4){
                ans = false;
            }
            ll div4 = n/4;
            ll div6 = n/6;
            ll rem4 = n%4;
            ll rem6 = n%6;
            ll mi=div6, ma=div4;
            if(rem6!=0 && rem6!=4 && rem6!=2){
                ans = false;
            }
            if(rem4!=0 && rem4!=2){
                ans = false;
            }
            if(rem6==4 || rem6==2){
                mi+=1;
            }
            if(ans){
                cout << mi << " " << ma << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
}