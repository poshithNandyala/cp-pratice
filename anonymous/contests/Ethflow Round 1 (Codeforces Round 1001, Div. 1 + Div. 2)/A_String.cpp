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
        string s;
        cin >> s;
        int n=s.size();
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') c++;
        }
        cout<<c<<endl;
    }
}