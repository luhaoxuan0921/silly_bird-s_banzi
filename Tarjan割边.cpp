#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200010;

vector<pair<int,int>> e[N];
int dfn[N],low[N],idx,n,m;
vector<int> bri;

void dfs(int u,int id){
	dfn[u]=low[u]=++idx;
	for(auto [v,id2]:e[u]){
		if(!dfn[v]){
			dfs(v,id2);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v])
				bri.push_back(id2);
		}else if(id!=id2)
			low[u]=min(low[u],dfn[v]);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	dfs(1,0);
	sort(bri.begin(),bri.end());
	printf("%d\n",(int)bri.size());
	for(auto x:bri) printf("%d ",x);
	puts("");
}