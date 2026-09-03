#include<bits/stdc++.h>
using namespace std;

unsigned int A, B, C;
long long ans;
inline unsigned int rng61() {
	A ^= A << 16;
	A ^= A >> 5;
	A ^= A << 1;
	unsigned int t = A;
	A = B;
	B = C;
	C ^= t ^ A;
	return C;
}

const int N=1000010;
int n,q,rt,a[2*N],l[N],d[N],st[22][N*2],f[N],idx,lg2[2*N];
vector<int> e[N];

void init(){
	lg2[1]=0;
	for(int i=2;i<2*N;i++)
		lg2[i]=lg2[i/2]+1;
}

void dfs(int x){
	idx++;
	l[x]=idx;
	a[idx]=x;
	for(int y:e[x]){
		d[y]=d[x]+1;
		dfs(y);
		a[++idx]=x;
	}
}

int lca(int u,int v){
	u=l[u],v=l[v];
	if(u>v) swap(u,v);
	int k=lg2[v-u+1];
	int p=st[k][u],q=st[k][v-(1<<k)+1];
	if(d[p]<d[q]) return p;
	return q;
}

int main(){
	init();
	scanf("%d%d%u%u%u", &n, &q, &A, &B, &C);
    for (int i = 1; i <= n; i++) {
    	scanf("%d",&f[i]);
    	if(!f[i]) rt=i;
    	else e[f[i]].push_back(i);
    }
    dfs(rt);
    for(int i=1;i<=idx;i++)
    	st[0][i]=a[i];
    for(int j=1;j<=21;j++){
    	for(int i=1;i+(1<<j)-1<=idx;i++){
    		int u=st[j-1][i],v=st[j-1][i+(1<<(j-1))];
    		if(d[u]<d[v]) st[j][i]=u;
    		else st[j][i]=v;
    	}
    }

    for (int i = 1; i <= q; i++) {
    	unsigned int u = rng61() % n + 1, v = rng61() % n + 1;
        ans ^= 1ll * i * lca(u, v);
    }
    printf("%lld\n", ans);
}
