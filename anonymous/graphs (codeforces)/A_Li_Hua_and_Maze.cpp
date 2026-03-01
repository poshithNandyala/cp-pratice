#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int f(int x,int y,int n,int m){
    if((x==1 || x==n) &&( y==1 || y==m)) return 2;
    if(x==1 || x==n || y==1 || y==m) return 3;
    return 4;
}
int32_t main() {
    fastio
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n>>m;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout<<min(f(x1,y1,n,m),f(x2,y2,n,m))<<endl;
    }
}
