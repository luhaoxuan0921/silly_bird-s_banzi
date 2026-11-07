#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int dfn[N],low[N],idx,n,m;
vector<pair<int,int>> e[N];
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

}