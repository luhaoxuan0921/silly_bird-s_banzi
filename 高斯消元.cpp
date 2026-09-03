#include<bits/stdc++.h>
using namespace std;
const int N=210;
const double eps=1e-10;

int n;
double a[N][N],b[N];

void gauss(){
	int l=1;
	for(int i=1;i<=n;i++){
		for(int j=l;j<=n;j++){
			if(abs(a[j][i])>abs(a[l][i])){
				for(int k=i;k<=n;k++)
					swap(a[l][k],a[j][k]);
				swap(b[l],b[j]);
			}
		}
		if(abs(a[l][i])<eps)
			continue;
		for(int j=1;j<=n;j++){
			if(j!=l&&abs(a[j][i])>eps){
				double delta=a[j][i]/a[l][i];
				for(int k=i;k<=n;k++)
					a[j][k]-=a[l][k]*delta;
				b[j]-=b[l]*delta;
			}
		}
		l++;
	}
	for(int i=l;i<=n;i++){
		if(abs(b[i])>eps){
			puts("-1");
			return;
		}
	}
	if(l<=n){
		puts("-2");
		return;
	}
	for(int i=1;i<=n;i++){
		printf("%.15f\n",b[i]/a[i][i]);
	}
}

int main(){

}