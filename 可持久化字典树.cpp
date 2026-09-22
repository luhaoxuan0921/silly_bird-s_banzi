#include<bits/stdc++.h>
using namespace std;
const int N=50005;

int n,a[N],ans;
int b[N],p[N];
int l1[N],l2[N],r1[N],r2[N];
int idx,rt[32*N];
struct Trie{
	int so[2],cnt;
}tr[32*N];

int ins(int old,int val){
	int rtn=++idx;
	tr[rtn]=tr[old];
	tr[rtn].cnt++;
	int cur_new=rtn,cur_old=old;
	for(int i=29;i>=0;i--){
		int x=(val>>i)&1;
		int nxt_new=++idx;
		int nxt_old=tr[cur_old].so[x];

		tr[nxt_new]=tr[nxt_old];
		tr[nxt_new].cnt++;
		tr[cur_new].so[x]=nxt_new;

		cur_new=nxt_new,cur_old=nxt_old;
	}
	return rtn;
}

int ques(int l,int r,int val){
	int cur_l=l,cur_r=r,sum=0;
	for(int i=29;i>=0;i--){
		int x=(val>>i)&1;
		int y=x^1;
		int& ly=tr[cur_l].so[y];
		int& ry=tr[cur_r].so[y];

		int cnt_l=0,cnt_r=0;
		if(ly) cnt_l=tr[ly].cnt;
		if(ry) cnt_r=tr[ry].cnt;

		if(cnt_r-cnt_l>0){
			sum+=1<<i;
			cur_l=ly;
			cur_r=ry;
		}else{
			cur_l=tr[cur_l].so[x];
			cur_r=tr[cur_r].so[x];
		}
	}
	return sum;
}

int main(){
	rt[0]=++idx;
}