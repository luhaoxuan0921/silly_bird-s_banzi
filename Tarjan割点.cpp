#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200010;

int dfn[N],low[N],idx,n,m,sz;
vector<int> e[N];
bool cut[N];

void dfs(int u,int fa){
	dfn[u]=low[u]=++idx;
	int ch=0;
	for(int v:e[u]){
		if(!dfn[v]){
			dfs(v,u);
			ch++;
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
				cut[u]=true;
		}else if(v!=fa){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(u==1&&ch<=1)
		cut[u]=0;
	sz+=cut[u];
}

int main(){

}