#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n,z[N];
string s;

void exkmp(){
	int l=1,r=0;
	z[1]=0;
	for(int i=2;i<=n;i++){
		if(i>r)
			z[i]=0;
		else
			z[i]=min(z[i-l+1],r-i+1);
		while(i+z[i]<=n&&s[z[i]+1]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r)
			l=i,r=i+z[i]-1;
	}
}

int main(){
	
}