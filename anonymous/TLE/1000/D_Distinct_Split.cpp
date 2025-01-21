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
        string s;
        cin >> s;
        vector<int> l(n),r(n);
        map<char,int> m1, m2;
        for(int i=0;i<n;i++){
            m1[s[i]]++;
            m2[s[n-i-1]]++;
            l[i] = m1.size();
            r[n-i-1] = m2.size();
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans = max(ans,l[i]+r[i+1]);
        }
        cout << ans << endl;
    }
}