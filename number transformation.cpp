#include<cstdio>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
LL a,b;//100000000000000000
int k,f[1000000]={0},gcm=1;
int gcd(int x,int y) {
	if (x%y==0) return y;
	else return gcd(y,x%y);
}
int cal(LL s,LL t) {
	//s=(s-1)%gcm+1;
	//t=t%gcm;
	int i;
	memset(f,1000000,sizeof(f));
	f[s]=0;
	for(i=s;i>t;i--) {
		for(int j=2;j<=k;j++) {
			f[i-i%j]=min(f[i-i%j],f[i]+1);
		}
		f[i-1]=min(f[i-1],f[i]+1);
	}
	return f[t];
}
int main() {
	scanf("%I64d%I64d%d",&a,&b,&k);
	int i;
	for(i=1;i<=k;i++)
		gcm=gcm*i/gcd(gcm,i);
	LL ans=0;

	if (a/gcm-b/gcm==0)
		ans=cal(a%gcm,b%gcm);
	else {
		if (a%gcm!=0)
			ans+=cal(a%gcm,0); 
		ans+=cal(gcm,0)*((a-b-a%gcm)/gcm);
		if (b%gcm!=0)
			ans+=cal(gcm,b%gcm);
	}
	printf("%I64d",ans);
	return 0;
}
