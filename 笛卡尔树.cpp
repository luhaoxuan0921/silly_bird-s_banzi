#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

int n,a[N],l[N],r[N],st[N],t,ans[N],tt;

void build(){
	for(int i=1;i<=n;i++){
		int last=0;
		while(t&&a[st[t]]>a[i]){
			last=st[t];
			t--;
		}
		if(t) r[st[t]]=i;
		l[i]=last;
		st[++t]=i;
	}
}

void dfs(int x){
	ans[x]=++tt;
	if(l[x])
		dfs(l[x]);
	if(r[x])
		dfs(r[x]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build();
	dfs(st[1]);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}