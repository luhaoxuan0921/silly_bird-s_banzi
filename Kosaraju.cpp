#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200010;

int n;
bool vis[N];
vector<int> e[N],erev[N];
vector<int> out,c;

void dfs1(int u){
	vis[u]=true;
	for(int v:e[u]){
		if(!vis[v]) dfs1(v);
	}
	out.push_back(u);
}

void dfs2(int u){
	vis[u]=true;
	for(int v:erev[u]){
		if(!vis[v]) dfs2(v);
	}
	c.push_back(u);
}

int main(){
	for(int i=1;i<=n;i++) if(!vis[i]){
		dfs1(i);
	}
	for(int i=1;i<=n;i++)
		vis[i]=false;
	for(int i=n-1;i>=0;i--) if(!vis[i]){
		c.clear();
		dfs2(out[i]);
	}
}