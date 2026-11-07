#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
const int mod=998244353;

ll inv[N],fac[N];

ll pw(ll x,int y){
	ll cnt=1LL;
	while(y){
		if(y&1)
			cnt=cnt*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return cnt;
}

inline void init(){
	fac[0]=1LL;
	for(int i=1;i<=200000;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[200000]=pw(fac[200000],mod-2);
	for(int i=200000;i;i--)
		inv[i-1]=inv[i]*i%mod;
}

ll C(int x,int y){
	return x<y?0LL:fac[x]*inv[x-y]%mod*inv[y]%mod;
}

int main(){

}