#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200010;
inline int lb(int& x){return x&(-x);}

vector<int> vx;
vector<array<int,4>> ev;
int n,q,m,c[N],ans[N];

void add(int x,int y){
	while(x<=n){
		c[x]+=y;
		x+=lb(x);
	}
}

int sum(int x){
	int cnt=0;
	while(x){
		cnt+=c[x];
		x-=lb(x);
	}
	return cnt;
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		vx.push_back(x);
		ev.push_back({y,0,x});
	}
	for(int i=1;i<=q;i++){
		int xx1,xx2,yy1,yy2;
		scanf("%d%d%d%d",&xx1,&xx2,&yy1,&yy2);
		ev.push_back({yy2,2,xx2,i});
		ev.push_back({yy1-1,2,xx1-1,i});
		ev.push_back({yy2,1,xx1-1,i});
		ev.push_back({yy1-1,1,xx2,i});
	}
	
	sort(ev.begin(),ev.end());
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());

	m=vx.size();
	for(auto evt:ev){
		if(evt[1]==0){
			int y=lower_bound(vx.begin(),vx.end(),evt[2])-vx.begin()+1;
			add(y,1);
		}else{
			int y=upper_bound(vx.begin(),vx.end(),evt[2])-vx.begin();
			int tmp=sum(y);
			if(evt[1]==1) ans[evt[3]]-=tmp;
			else ans[evt[3]]+=tmp;
		}
	}

	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}