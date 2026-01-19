#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> indeg(n,0),sem(n,0);
		vector<vector<int>> adjlist(n);
    for(int i=0;i<m;i++){
    	int x,y;
    	cin>>x>>y;
    		adjlist[x].push_back(y);
    	indeg[y]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
    	if(!indeg[i]){
    		q.push(i);
    		sem[i]=1;
    	}
    }
    int ans=1;
    while(!q.empty()){
    	int curr=q.front();
    	q.pop();
    	for(int i=0;i<adjlist[curr].size();i++){
    		int nbr=adjlist[curr][i];
         		if(--indeg[nbr]==0){
                          q.push(nbr);
                          sem[nbr] = sem[curr] + 1;
                }
    	}
    }

    for(int i=0;i<n;i++){
    	cout<<sem[i]<<" ";
      ans = max(ans, sem[i]);
    }
    cout<<endl;
    cout<<ans<<endl;
}