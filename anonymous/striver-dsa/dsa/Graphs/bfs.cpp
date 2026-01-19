#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> dist(n+1,-1);
	vector<vector<int>> adjlist(n+1);
    for(int i=0;i<m;i++){
    	int x,y;
    	cin>>x>>y;
    	adjlist[x].push_back(y);
    	adjlist[y].push_back(x);
    }
    queue<int> q;
    int src;
    cin>>src;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
    	int curr=q.front();
    	q.pop();
    	for(int i=0;i<adjlist[curr].size();i++){
    		if(dist[adjlist[curr][i]]==-1){
                   dist[adjlist[curr][i]]=dist[curr]+1;
                   q.push(adjlist[curr][i]);
    		}
    	}
    }
    for(int i=1;i<=n;i++){
    	cout<<i<<" "<<dist[i]<<endl;
    }
}