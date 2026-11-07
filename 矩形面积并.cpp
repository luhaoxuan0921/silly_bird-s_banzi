//这是点版本！！！！！
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
struct Sgtr{
	int v,vx,t;
};

int n,m;
ll ans;
vector<int> vx;
vector<array<int,4>> ev;
Sgtr s[4*N];

void upp(int id){
	s[id].v=min(s[2*id].v,s[2*id+1].v);
	if(s[2*id].v==s[2*id+1].v)
		s[id].vx=s[2*id].vx+s[2*id+1].vx;
	else if(s[2*id].v<s[2*id+1].v)
		s[id].vx=s[2*id].vx;
	else s[id].vx=s[2*id+1].vx;
}

void down(int id){
	if(s[id].t){
		s[2*id].t+=s[id].t;
		s[2*id].v+=s[id].t;
		s[2*id+1].t+=s[id].t;
		s[2*id+1].v+=s[id].t;
		s[id].t=0;
	}
}

void build(int id,int l,int r){
	if(l==r){
		s[id].v=0;
		s[id].vx=vx[r]-vx[r-1];
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
	if(qr<=mid)
		lc(2*id,l,mid,ql,qr,d);
	else if(ql>mid)
		lc(2*id+1,mid+1,r,ql,qr,d);
	else{
		lc(2*id,l,mid,ql,mid,d);
		lc(2*id+1,mid+1,r,mid+1,qr,d);
	}
	upp(id);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int xx1,xx2,yy1,yy2;
		scanf("%d%d%d%d",&xx1,&xx2,&yy1,&yy2);
		if(xx1==xx2||yy1==yy2) continue;
		vx.push_back(xx1);
		vx.push_back(xx2);
		ev.push_back({yy1,1,xx1,xx2});
		ev.push_back({yy2,-1,xx1,xx2});
	}
	
	sort(ev.begin(),ev.end());
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());

	m=vx.size()-1;
	build(1,1,m);
	int tot=s[1].vx,p=0;
	for(auto evt:ev){
		int cov=tot;
		if(s[1].v==0)
			cov=tot-s[1].vx;
		ans+=1LL*(evt[0]-p)*cov;
		p=evt[0];
		int xx1=lower_bound(vx.begin(),vx.end(),evt[2])-vx.begin()+1;
		int xx2=lower_bound(vx.begin(),vx.end(),evt[3])-vx.begin();
		if(xx1>xx2) continue;
		lc(1,1,m,xx1,xx2,evt[1]);
	}
	printf("%lld\n",ans);
}