#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
const ll inf=1LL<<60;

int n,p[N];
ll v[N],dp[N][2],f[N][2],ans;
vector<int> e[N];
bool vis[N],on[N];

void dfs(int u){
	vis[u]=true;
	dp[u][1]=v[u];
	for(int v:e[u]){
		if(on[v]) continue;
		dfs(v);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%d",&v[i],&p[i]);
		e[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int u=i;
		while(!vis[u]){
			vis[u]=true;
			u=p[u];
		}

		int v=u;
		vector<int> cyc;
		while(true){
			cyc.push_back(v);
			on[v]=true;
			v=p[v];
			if(v==u) break;
		}
		for(int v:cyc)
			dfs(v);
		
		int m=cyc.size();
		ll ans2=-inf;
		for(int t=0;t<2;t++){
			for(int j=0;j<2;j++){
				if(j==t) f[0][j]=dp[cyc[0]][j];
				else f[0][j]=-inf;
			}
			for(int i=1;i<=m;i++){
				int u=cyc[i];
				f[i][0]=max(f[i-1][0],f[i-1][1])+dp[u][0];
				f[i][1]=f[i-1][0]+dp[u][1];
			}
			if(t==0)
				ans2=max(ans2,max(f[m-1][0],f[m-1][1]));
			else
				ans2=max(ans2,f[m-1][0]);
		}
		ans+=ans2;
	}
	printf("%lld\n",ans);
}