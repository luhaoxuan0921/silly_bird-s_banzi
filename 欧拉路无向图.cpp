#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int M=200010;

vector<array<int,2>> e[N];
int n,m,l,cnt=1,f[N],d[N],c[M];
bool b[2*M];

void dfs(int x){
	while(f[x]<d[x]){
		auto [y,idx]=e[x][f[x]];
		if(!b[idx]){
			b[idx]=b[idx^1]=true;
			dfs(y);
			c[++l]=y;
		}
		f[x]++;
	}
}

void Euler(){
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(d[i]&1)
			x=i,y++;
	}
	if(y&&y!=2){
		puts("No");
		return;
	}
	if(!x){
		for(int i=1;i<=n;i++){
			if(d[i])
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