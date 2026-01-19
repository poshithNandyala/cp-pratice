#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adjlist;
vector<int> dp;
int dfs(int cur,int par){
   int ans=1;
   for(int i:adjlist[cur]){
   	 ans+=dfs(i,cur);
   }
   return dp[cur]=ans;
}
int main(){
	int n;
	cin>>n;
	adjlist.resize(n);
	dp.resize(n);
	for(int i=0;i<n-1;i++){
          int x,y;
          cin>>x>>y;
          adjlist[x].push_back(y);
	}
	dfs(0,-1);
	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}
}