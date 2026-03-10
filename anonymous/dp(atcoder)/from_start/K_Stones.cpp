#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rec(int player,int k,vector<int> &a,vector<vector<int>> &dp){
   if(a[0] > k) {
      return (player==0);
   }
   if(dp[player][k]!=-1) return dp[player][k];
   for(int i=0;i<a.size();i++){
      if(a[i] <= k  && rec(1-player,k-a[i],a,dp)==player){
      return dp[player][k]=player;
      }
   }
   return dp[player][k]=1-player;
}

int main(){
   int n,k;
   cin>>n>>k;
   
   vector<int> a(n);
   for(int i=0;i<n;i++){
         cin>>a[i];
   }
   sort(a.begin(),a.end());
   vector<vector<int>> dp(2,vector<int>(k+1,-1));
   if(rec(0,k,a,dp)==0){
   cout<<"First"<<endl;
   }
   else{
     cout<<"Second"<<endl;
   }
}

    