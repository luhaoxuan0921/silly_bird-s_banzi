#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n,m,nxt[N],f[N];
string s,p;

void kmp(){
	int j=0;
	nxt[1]=0;
	for(int i=2;i<=m;i++){
		while(j>0&&p[j+1]!=p[i])
			j=nxt[j];
		if(p[j+1]==p[i])
			j++;
		nxt[i]=j;
	}

	j=0;
	for(int i=1;i<=n;i++){
		while((j==m)||(j>0&&p[j+1]==s[i]))
			j=nxt[j];
		if(p[j+1]==s[i])
			j++;
		f[i]=j;
	}
}

int main(){

}