#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int M=200010;

int n,m,l,f[N],v[N],ind[N],oud[N],c[M];
vector<int> e[N];

void dfs(int x){
	while(f[x]<oud[x]){
		int y=e[x][f[x]];
		f[x]++;
		dfs(y);
		c[++l]=y;
	}
}

void Euler(){
	int x=0,y=0,z=0;
	for(int i=1;i<=n;i++){
		if(ind[i]+1==oud[i])
			x=i,y++;
		if(ind[i]!=oud[i])
			z++;
	}
	if(!((y==1&&z==2)||z==0)){
		puts("No");
		return;
	}
	if(!x){
		for(int i=1;i<=n;i++){
			if(ind[i])
				x=i;
		}
	}
	l=0;
	dfs(x);
	c[++l]=x;
	if(l!=m+1){
		puts("No");
		return;
	}
	puts("Yes");
	for(int i=l;i;i--)
		printf("%d ",c[i]);
}

int main(){	

}