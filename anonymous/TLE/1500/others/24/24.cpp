#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,pair<int,int> > > v;
		
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back({x,{y,i}});
			
		}
		sort(v.begin(),v.end());
	
		int final=v[0].second.first;
		int ans=-1;
		vector<int> vans(n,2);
		vans[v[0].second.second]=1;
		for(int i=1;i<n;i++){
			if(v[i].first<=final){
				final=max(v[i].second.first,final);
				vans[v[i].second.second]=1;
			}
			else{
				ans=i;
				break;
			}
		}
		if(ans==-1){
			cout<<ans;
		}
		else{
			for(int i=0;i<n;i++){
				cout<<vans[i]<<" ";
			}
		}
		cout<<endl;
	}
}