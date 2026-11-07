#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n,m,p[N];
char s[N];

void manacher(){
	int L=0,R=0;
	for(int i=1;i<=m;i++){
		if(i>R) p[i]=1;
		else p[i]=min(p[L+L-i],R-i+1);
		while(i-p[i]>0&&i+p[i]<=m&&s[i-p[i]]==s[i+p[i]])
			p[i]++;
		if(i+p[i]-1>R)
			L=i,R=i+p[i]-1;
	}
}

int main(){

}