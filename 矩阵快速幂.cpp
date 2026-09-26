#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=7+1e9;

struct Mtrx{
	int x,y;
	ll a[2][2];
	Mtrx operator * (const Mtrx& b){
		if(y!=b.x){
			printf("RE!\n%d %d %d %d\n",x,y,b.x,b.y);
			exit(-1);
		}
		Mtrx tmp;
		tmp.x=x,tmp.y=b.y;
		for(int i=0;i<x;i++){
			for(int j=0;j<b.y;j++){
				tmp.a[i][j]=0;
				for(int k=0;k<y;k++)
					tmp.a[i][j]=(tmp.a[i][j]+a[i][k]*b.a[k][j])%mod;
			}
		}
		return tmp;
	}
};

int main(){
	
}