#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
const LL MOD=1000000000+7;
LL max(LL a,LL b)
{if (a<b) return b;else return a;
}
LL min(LL a,LL b)
{return a+b-max(a,b);
} 
int main()
{
	LL n,m,ans=0;
	scanf("%lld%lld",&n,&m);
	ans=0;
	LL i,d;
	for(i=1;i<min(m+1,sqrt(n));i++)
		ans=(ans+i*(n/i%MOD)%MOD)%MOD;
	for(d=n/i;d>=max(n/m,1);d--)
	{
		LL s=n/(d+1)+1,t=min(n/d,m);
		//ans=(ans+d%MOD*(s+t)*(t-s+1)/2%MOD)%MOD;
		ans=(ans+d%MOD*((((t-s+1)%MOD*((t-s)%MOD+2*(s%MOD)))/2)%MOD))%MOD;
		//ans=(ans+d%MOD*((((t-s)%MOD)*((t-s+1)%MOD)/2+s*(t-s+1)%MOD)%MOD))%MOD;
	}
	ans=(m%MOD*(n%MOD)%MOD-ans+MOD)%MOD;
	printf("%lld",ans);
	return 0;	
} 
