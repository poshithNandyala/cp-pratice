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
        vector<ll> a(n+1);
        ll sum = 0;
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        map<ll, ll> indeg;  
        for (int i = 1;i<n;i++){
            ll u, v;
            cin >> u >> v;
            indeg[v]++;
            indeg[u]++;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<indeg[i]<<" ";
        // }
        // cout << endl;
        vector<pair<ll, ll>> v;
        for(int i = 1; i <= n; i++){
            if(indeg[i]>1){
                v.push_back({a[i], indeg[i]});
            }
        }
        sort(v.begin(), v.end(),greater<pair<ll, ll>>());
        // for(auto item : v){
        //     cout << item.first << " " << item.second << " " << endl;
        // }
        // cout << "\n";
        
        cout<<sum<<" ";
        int i = 0;
        while(i<v.size()){
            while(v[i].second>1) {
                v[i].second--;
                sum+= v[i].first;
                cout<<sum<<" ";
            }
            i++;
        }    
        cout<<endl;   
    }
}