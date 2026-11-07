#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n,m,nxt[N];
char s[N];

void kmp(){
	nxt[1]=0;
	for(int i=2,j=0;i<=m;i++){
		while(j>0&&s[j+1]!=s[i])
			j=nxt[j];
		if(s[j+1]==s[i])
			j++;
		nxt[i]=j;
	}
}

int main(){

}