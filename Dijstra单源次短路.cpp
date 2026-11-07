#include<bits/stdc++.h>
using namespace std;

int n,m,d[5010][2];
vector<pair<int,int>> e[5010];
set<pair<int,int>> s;

void dij(){
	for(int i=1;i<=n;i++)
		d[i][0]=d[i][1]=1<<30;
	d[1][0]=0;
	for(int i=1;i<=n;i++){
		s.insert({d[i][0],i});
		s.insert({d[i][1],i+n});
	}
	while(!s.empty()){
		int u=s.begin()->second,x=0;
		s.erase(s.begin());
		// printf("%d %d\n",u,x);
		if(u>n)
			u-=n,x=1;
		for(auto [v,w]:e[u]){
			int cnt=d[u][x]+w;
			if(cnt<d[v][0]){
				s.erase({d[v][0],v});
				s.erase({d[v][1],v+n});
				d[v][1]=d[v][0];
				d[v][0]=cnt;
				s.insert({d[v][0],v});
				s.insert({d[v][1],v+n});
			}else if(cnt>d[v][0]){
				if(cnt<d[v][1]){
					s.erase({d[v][1],v+n});
					d[v][1]=cnt;
					s.insert({d[v][1],v+n});
				}
			}
		}
	}
}

int main(){

}