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
        int a, b,xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        map<pair<int,int>,int> king,queen;
        king[{xk + a, yk + b}] = 1;
        queen[{xq + a, yq + b}] = 1;
        king[{xk + a, yk - b}] = 1;
        queen[{xq + a, yq - b}] = 1;
        king[{xk - a, yk + b}] = 1;
        queen[{xq - a, yq + b}] = 1;
        king[{xk - a, yk - b}] = 1;
        queen[{xq - a, yq - b}] = 1;
        king[{xk + b, yk + a}] = 1;
        queen[{xq + b, yq + a}] = 1;
        king[{xk + b, yk - a}] = 1;
        queen[{xq + b, yq - a}] = 1;
        king[{xk - b, yk + a}] = 1;
        queen[{xq - b, yq + a}] = 1;
        king[{xk - b, yk - a}] = 1;
        queen[{xq - b, yq - a}] = 1;
        int ans = 0;
        for(auto it: king){
            if(queen[it.first]){
                ans++;
            }
        }
        cout << ans << endl;
    }
}