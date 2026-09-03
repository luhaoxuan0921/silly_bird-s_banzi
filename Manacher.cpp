#include<bits/stdc++.h>
using namespace std;
const int N=100010;

int n,m,p[N];
string s,t;

int manacher(){
	n=s.size();
	s=' '+s;
	t=" ";
	t+='#';
	m++;
	for(int i=1;i<=n;i++)
		t+=s[i],m++,t+='#',m++;

	int M=0,R=0;
	for(int i=1;i<=m;i++){
		if(i>R)
			p[i]=1;
		else
			p[i]=min(p[2*M-i],R-i+1);
		while(i-p[i]>0&&i+p[i]<=m&&t[i-p[i]]==t[i+p[i]])
			++p[i];
		if(i+p[i]-1>R)
			M=i,R=i+p[i]-1;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		ans=max(ans,p[i]);
	return ans;
}

int main(){

}