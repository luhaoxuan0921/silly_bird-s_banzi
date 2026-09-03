#include<bits/stdc++.h>
using namespace std;

const int N=5000010;
const int inf=1<<30;
mt19937 mrand(1);

struct Node{
	int val,p,sz,l,r,ls,rs,ms,sum;
	bool rev;
	int fs;
}t[N];

int cur=0,rt=0,n,m,a[N];

void setf(int p){
	if(!p) return;
	t[p].rev^=1;
	swap(t[p].l,t[p].r);
	swap(t[p].ls,t[p].rs);
}

void sets(int p,int v){
	if(!p) return;
	t[p].fs=t[p].val=v;
	t[p].sum=t[p].sz*v;
	if(v>=0){
		t[p].ls=t[p].rs=t[p].ms=t[p].sum;
	}else{
		t[p].ls=t[p].rs=0;
		t[p].ms=v;
	}
}

void push(int p){
	if(t[p].rev){
		setf(t[p].l);
		setf(t[p].r);
		t[p].rev=false;
	}
	if(t[p].fs!=-inf){
		sets(t[p].l,t[p].fs);
		sets(t[p].r,t[p].fs);
		t[p].fs=-inf;
	}
}

void upd(int p){
	t[p].sz=1;
	if(t[p].l) t[p].sz+=t[t[p].l].sz;
	if(t[p].r) t[p].sz+=t[t[p].r].sz;
	t[p].sum=t[t[p].l].sum+t[t[p].r].sum+t[p].val;
	t[p].ls=max(t[t[p].l].sum+t[p].val+t[t[p].r].ls,t[t[p].l].ls);
	t[p].rs=max(t[t[p].r].sum+t[p].val+t[t[p].l].rs,t[t[p].r].rs);
	t[p].ms=max(t[t[p].l].ms,max(t[t[p].r].ms,t[t[p].l].rs+t[p].val+t[t[p].r].ls));
}

int newnode(int a){
	++cur;
	if(a>=0)
		t[cur]=(Node){a,(int)mrand(),1,0,0,a,a,a,a,false,-inf};
	else
		t[cur]=(Node){a,(int)mrand(),1,0,0,0,0,a,a,false,-inf};
	return cur;
}

void split(int p,int sz,int& l,int& r){
	if(!p){
		l=r=0;
		return;
	}
	push(p);
	if(t[t[p].l].sz<sz){
		l=p;
		split(t[p].r,sz-t[t[p].l].sz-1,t[p].r,r);
	}else{
		r=p;
		split(t[p].l,sz,l,t[p].l);
	}
	upd(p);
}

int merge(int l,int r){
	if((!l)||(!r))
		return l+r;
	if(t[l].p<t[r].p){
		push(l);
		t[l].r=merge(t[l].r,r);
		upd(l);
		return l;
	}else{
		push(r);
		t[r].l=merge(l,t[r].l);
		upd(r);
		return r;
	}
}

void debug(int p){
	if(!p) return;
	debug(t[p].l);
	printf("%d %d %d %d %d\n",p,t[p].l,t[p].r,t[p].val,t[p].sum);
	debug(t[p].r);
}

int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	t[0].ms=-inf;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		newnode(a[i]);
		rt=merge(rt,cur);
		// printf("%d %d\n",i,a[i]);
	}
	// debug(rt);
	string s;
	int posi,tot;
	while(m--){
		cin>>s;
		if(s=="INSERT"){
			cin>>posi>>tot;
			int rt1=0;
			for(int i=1,c;i<=tot;i++){
				cin>>c;
				rt1=merge(rt1,newnode(c));
			}
			int l,r;
			split(rt,posi,l,r);
			rt=merge(merge(l,rt1),r);

		}else if(s=="DELETE"){
			cin>>posi>>tot;
			tot+=posi-1;;
			int l,mid,r;
			split(rt,tot,l,r);
			split(l,posi-1,l,mid);
			rt=merge(l,r);

		}else if(s=="MAKE-SAME"){
			cin>>posi>>tot;
			int c;
			cin>>c;
			tot+=posi-1;;
			int l,mid,r;
			split(rt,tot,l,r);
			split(l,posi-1,l,mid);
			sets(mid,c);
			rt=merge(merge(l,mid),r);

		}else if(s=="REVERSE"){
			cin>>posi>>tot;
			tot+=posi-1;;
			int l,mid,r;
			split(rt,tot,l,r);
			split(l,posi-1,l,mid);
			setf(mid);
			rt=merge(merge(l,mid),r);

		}else if(s=="GET-SUM"){
			cin>>posi>>tot;
			tot+=posi-1;
			// printf("%d %d\n",posi,tot);
			int l,mid,r;
			split(rt,tot,l,r);
			split(l,posi-1,l,mid);
			// printf("%d %d %d\n",l,mid,r);
			printf("%d\n",t[mid].sum);
			rt=merge(merge(l,mid),r);

		}else if(s=="MAX-SUM"){
			printf("%d\n",t[rt].ms);

		}
		puts("");
	}
}