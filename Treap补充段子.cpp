#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
using ll=long long;
const int N=2000100;
mt19937 mrand(1);

ui randNum(ui& seed, ui last, const ui m){ 
    seed = seed * 17 + last;
    return seed % m + 1; 
}

struct info{
	ll a,b;
}wss[N];

bool operator < (info &x,info &y){
	if(x.a!=y.a) return x.a>y.a;
	return x.b<y.b;
}

bool operator == (info &x,info &y){
	return (x.a==y.a&&x.b==y.b);
}

bool operator <= (info &x,info &y){
	return (x<y||x==y);
}

struct node{
	info val;
	int p,sz,l,r;
}t[N];

ui seed,last=7;
int cur=0,rt=0,n,m;

inline void upd(int p){
	t[p].sz=1;
	if(t[p].l) t[p].sz+=t[t[p].l].sz;
	if(t[p].r) t[p].sz+=t[t[p].r].sz;
}

inline int newnode(info a){
	++cur;
	t[cur]=(node){a,(int)mrand(),1,0,0};
	return cur;
}

inline void split(int p,info &key,int &l,int &r){
	if(!p){
		l=r=0;
		return;
	}
	if(t[p].val<key){
		l=p;
		split(t[p].r,key,t[p].r,r);
	}else{
		r=p;
		split(t[p].l,key,l,t[p].l);
	}
	upd(p);
}

inline void split1(int p,info &key,int &l,int &r){
	if(!p){
		l=r=0;
		return;
	}
	if(t[p].val<=key){
		l=p;
		split1(t[p].r,key,t[p].r,r);
	}else{
		r=p;
		split1(t[p].l,key,l,t[p].l);
	}
	upd(p);
}

inline int merge(int l,int r){
	if((!l)||(!r))
		return l+r;
	if(t[l].p<t[r].p){
		t[l].r=merge(t[l].r,r);
		upd(l);
		return l;
	}else{
		t[r].l=merge(l,t[r].l);
		upd(r);
		return r;
	}
}

inline int lu(info &x){
	int ans=0,p=rt;
	while(p){
		if(t[p].val<x){
			ans+=t[t[p].l].sz+1;
			p=t[p].r;
		}else{
			p=t[p].l;
		}
	}
	return ans;
}

inline void jddebug(int p){
	if(!p) return;
	jddebug(t[p].l);
	printf("%d %d %d %d %d\n",p,t[p].l,t[p].r,t[p].val.a,t[p].val.b);
	jddebug(t[p].r);
}

inline void solve(){
	cur=0;
	rt=1;
	scanf("%d%d%d",&m,&n,&seed);
	for(int i=1;i<=m;i++){
		newnode((info){0,0});
		wss[i]=(info){0,0};
	}
	for(int i=2;i<=m;i++)
		rt=merge(rt,i);
	// printf("%d\n",rt);
	// jddebug(rt);
	while(n--){
		ll ria=randNum(seed,last,m),rib=randNum(seed,last,m);
		// printf("%d %d\n",ria,rib);
		info x=wss[ria];
		// printf("%d %d\n",x.a,x.b);
		int l,r,mid;
		split1(rt,x,l,r);
		split(l,x,l,mid);
		// printf("%d %d\n",l,r);
		mid=merge(t[mid].l,t[mid].r);
		// printf("%d %d %d\n",t[r].l,r,mid);
		rt=merge(merge(l,mid),r);
		// printf("%d %d\n",mid,rt);
		//删

		info y={x.a+1LL,x.b+rib};
		// int l,r;
		newnode(y);
		split(rt,y,l,r);
		rt=merge(merge(l,cur),r);
		// printf("%d\n",rt);
		// 加
		int z=lu(y);
		printf("%d\n",z);
		// printf("%d\n",rt);
		// jddebug(rt);
		// puts("");
		last=(ui)z;
		wss[ria].a++;
		wss[ria].b+=rib;
	}
}

int main(){
	int tt=1;
	scanf("%d",&tt);
	while(tt--){
		solve();
	}
}