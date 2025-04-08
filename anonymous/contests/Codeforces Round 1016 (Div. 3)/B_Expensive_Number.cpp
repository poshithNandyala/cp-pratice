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
        int n = s.size();
        int cnt = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]-'0'){
                cnt++;
            }
        }
        for (int i = n - 1;i>=0;i--) {
            if (s[i] - '0') {
                break;
            }
            else{
                ans++;
            }
        }
        cout<<cnt+ans-1<<endl;
    }
}