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
        int l = 0;
        int r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(mid * mid < n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(l * l == n){
            cout << l << endl;
        }else if(r * r == n){
            cout << r << endl;
        }else{
            cout << "not perfect square" << endl;
        }
    }
}