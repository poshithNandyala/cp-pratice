#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<string> &s){
    s[i][j]='#';
    vector<pair<int,int>> dir={
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    for (auto it:dir){
        int newi=i+it.first,newj=j+it.second;
        if(newi>=0 && newi<s.size() && newj>=0 && newj< s[0].size() && s[newi][newj]=='.'){
            dfs(newi,newj,s);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.'){
                dfs(i,j,s);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}