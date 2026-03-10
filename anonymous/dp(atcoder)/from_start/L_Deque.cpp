#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

/*
Problem:
Two players remove numbers from either end of the array.
Taro goes first.

X = score of Taro
Y = score of Jiro

Both play optimally.

Goal: Print X - Y
*/

long long rec(int player,int i,int j,vector<long long> &a,
              vector<vector<long long>> &dp){

    if(i>j) return 0;

    if(dp[i][j]!=LLONG_MIN) return dp[i][j];

    if(player==0){
        return dp[i][j] = max(
            a[i] + rec(1,i+1,j,a,dp),
            a[j] + rec(1,i,j-1,a,dp)
        );
    }
    else{
        return dp[i][j] = min(
            rec(0,i+1,j,a,dp) - a[i],
            rec(0,i,j-1,a,dp) - a[j]
        );
    }
}

int main(){

    int n;
    cin>>n;

    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<vector<long long>> dp(n,vector<long long>(n,LLONG_MIN));

    cout<<rec(0,0,n-1,a,dp)<<endl;
}