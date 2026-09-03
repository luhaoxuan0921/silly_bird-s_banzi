#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200010;

int n,q;
ll a[N];

struct Node{
	ll v,t;
}s[4*N];

void upp(int id){
	s[id].v=max(s[2*id].v,s[2*id+1].v);
}

void down(int id){
	if(s[id].t==0) return;
	s[2*id].t+=s[id].t;
	s[2*id].v+=s[id].t;
	s[2*id+1].t+=s[id].t;
	s[2*id+1].v+=s[id].t;
	s[id].t=0;
}

void build(int id,int l,int r){
	s[id].t=0;
	if(l==r){
		s[id].v=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	upp(id);
}

void lc(int id,int l,int r,int ql,int qr,ll d){
	if(ql==l&&qr==r){
		s[id].t+=d;
		s[id].v+=d;
		return;
	}
	down(id);
	int mid=(l+r)>>1;
	if(qr<=mid) lc(2*id,l,mid,ql,qr,d);
	else if(ql>mid) lc(2*id+1,mid+1,r,ql,qr,d);
	else{
		lc(2*id,l,mid,ql,mid,d);
		lc(2*id+1,mid+1,r,mid+1,qr,d);
	}
	upp(id);
}

ll ques(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr)
		return s[id].v;
	
	down(id);
	int mid=(l+r)>>1;
	if(qr<=mid)
		return ques(2*id,l,mid,ql,qr);
	if(ql>mid)
		return ques(2*id+1,mid+1,r,ql,qr);

	return max(ques(2*id,l,mid,ql,mid),ques(2*id+1,mid+1,r,mid+1,qr));
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n);

	while(q--){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int l,r;
			ll d;
			scanf("%d%d%lld",&l,&r,&d);
			lc(1,1,n,l,r,d);
		}else{
			int l,r;
			scanf("%d%d",&l,&r);
			auto ans=ques(1,1,n,l,r);
			printf("%lld\n",ans);
		}
	}
}