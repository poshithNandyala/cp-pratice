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
        int a, b, c;
        cin >> a >> b >> c;
        int a1 = 2*b - c;
        int b1 = (a+c)/2;
        if((a+c)%2){
            b1 = b - 1;
        }
        int c1 = 2*b - a;
        // cout<<a1<<" "<<b1<<" "<<c1<<endl;
        if((a1%a == 0 && a1>0 )|| (b1%b == 0 && b1>0 )|| (c1%c == 0 && c1>0)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}