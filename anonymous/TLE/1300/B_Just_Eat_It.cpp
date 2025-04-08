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
        vector<ll> a(n);
        ll sum = 0,yasseer=0, maxSum = INT_MIN,tempMax=INT_MIN;
        for(ll i=0; i<n; i++){
            cin >> a[i];
            yasseer += a[i];
        }
        for(ll i=1; i<n; i++){
            sum+= a[i];
            tempMax = max(tempMax, sum);
            if(sum<0){
                sum = 0;
            }
        }
        sum = 0;      
        for(ll i=0; i<n-1; i++){
            sum += a[i];
            tempMax = max(tempMax, sum);
            if(sum<0){
                sum = 0;
            }
        }
        // cout << "tempMax: " << tempMax << endl;
        if(yasseer>tempMax){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}