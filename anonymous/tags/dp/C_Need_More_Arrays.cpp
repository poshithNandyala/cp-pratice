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
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int i = 0;
        int j = 1;
        int ans = 1;
        while(i<n && j<n){
            while((a[j]-a[i] )< 2 && j < n){
                j++;
            }
            if(j < n && (a[j] - a[i]) >= 2){
                ans++;
            }
            i = j;
        }
        cout << ans << endl;
    }
}