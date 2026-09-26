#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n,q,a[N];

struct Sgtr{
	int v;
}s[4*N];

void upp(int id){
	s[id].v=min(s[2*id].v,s[2*id+1].v);
}

void build(int id,int l,int r){
	if(l==r){
		s[id].v=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	upp(id);
}

void change(int id,int l,int r,int u,int us){
	if(l==r){
		s[id].v=us;
		return;
	}
	int mid=(l+r)>>1;
	if(u<=mid) change(2*id,l,mid,u,us);
	else change(2*id+1,mid+1,r,u,us);
	upp(id);
}

int ques(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr)
		return s[id].v;
	
	int mid=(l+r)>>1;
	if(qr<=mid)
		return ques(2*id,l,mid,ql,qr);
	if(ql>mid)
		return ques(2*id+1,mid+1,r,ql,qr);

	return min(ques(2*id,l,mid,ql,mid),ques(2*id+1,mid+1,r,mid+1,qr));
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);

	while(q--){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int x,d;
			scanf("%d%d",&x,&d);
			change(1,1,n,x,d);
		}else{
			int l,r;
			scanf("%d%d",&l,&r);
			auto ans=ques(1,1,n,l,r);
			printf("%d\n",ans);
		}
	}
}