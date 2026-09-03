#include<bits/stdc++.h>
using namespace std;
const int N=100010;
mt19937 mrand(1);

struct Node{
	int val,p,sz,l,r;
}t[N];

int cur,rt,n;

void upd(int p){
	t[p].sz=1;
	if(t[p].l) t[p].sz+=t[t[p].l].sz;
	if(t[p].r) t[p].sz+=t[t[p].r].sz;
}

int newnode(int a){
	++cur;
	t[cur]=(Node){a,(int)mrand(),1,0,0};
	return cur;
}

void split(int p,int key,int &l,int &r){
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

int merge(int l,int r){
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

int kth(int k){
	int p=rt;
	while(true){
		if(t[t[p].l].sz>=k)
			p=t[p].l;
		else if(t[t[p].l].sz+1<k){
			k-=t[t[p].l].sz+1;
			p=t[p].r;
		}else return t[p].val;
	}
}

int suc(int x){
	int p=rt,ans=-1;
	while(p){
		if(t[p].val<=x)
			p=t[p].r;
		else{
			ans=t[p].val;
			p=t[p].l;
		}
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	while(n--){
		int ty,x;
		scanf("%d%d",&ty,&x);
		if(ty==1){
			int l,r;
			int c=newnode(x);
			split(rt,x,l,r);
			rt=merge(merge(l,c),r);

		}else if(ty==2){
			int l,r,mid;
			split(rt,x+1,l,r);
			split(l,x,l,mid);
			mid=merge(t[mid].l,t[mid].r);
			rt=merge(merge(l,mid),r);

		}else if(ty==3){
			int l,r;
			split(rt,x,l,r);
			printf("%d\n",t[l].sz+1);
			rt=merge(l,r);

		}else if(ty==4){
			printf("%d\n",kth(x));

		}else if(ty==5){
			int l,r;
			split(rt,x,l,r);
			int x=l;
			while(t[x].r)
				x=t[x].r;
			printf("%d\n",t[x].val);
			rt=merge(l,r);

		}else{
			printf("%d\n",suc(x));
		}
		puts("");
	}
}