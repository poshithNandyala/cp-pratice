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
        int n,c;
        cin >> n >> c;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] += (i+1);
        }
        sort(a,a+n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > c) break;
            c -= a[i];
            ans++;
        }
        cout << ans << endl;
    }
}