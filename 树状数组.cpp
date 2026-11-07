#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
inline int lb(int x){return x&(-x);}

int n,q;
ll a[N],c[N];

void add(int x,ll y){
	while(x<=n){
		c[x]+=y;
		x+=lb(x);
	}
}

ll sum(int x){
	ll cnt=0LL;
	while(x){
		cnt+=c[x];
		x-=lb(x);
	}
	return cnt;
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		add(i,a[i]);
	}
	while(q--){
		int type;
		scanf("%d",&type);
		if(type==1){
			int x;
			ll y;
			scanf("%d%lld",&x,&y);
			add(x,y-a[x]);
			a[x]=y;
		}else{
			int x;
			scanf("%d",&x);
			printf("%lld\n",sum(x));
		}
	}
}