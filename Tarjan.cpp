#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200010;

int dfn[N],low[N],bel[N],cnt,idx;
bool ins[N];
vector<int> e[N];
vector<vector<int>> scc;
stack<int> stk;

void dfs(int u){
	dfn[u]=low[u]=++idx;
	ins[u]=true;
	stk.push(u);
	for(int v:e[u]){
		if(!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else{
			if(ins[v])
				low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		vector<int> c;
		cnt++;
		while(true){
			int v=stk.top();
			c.push_back(v);
			bel[v]=cnt;
			ins[v]=false;
			stk.pop();
			if(v==u) break;
		}
		sort(c.begin(),c.end());
		scc.push_back(c);
	}
}

int main(){

}