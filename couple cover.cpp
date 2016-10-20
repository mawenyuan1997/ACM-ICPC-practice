#include<cstdio>
#define LL long long
using namespace std;
const LL maxa=3e6,maxn=1e6;
LL ans[maxa+1]={0},n,m,cnt[maxa+1]={0},z[maxa+1];
LL a[maxn+1];
int main()
{
	scanf("%lld",&n);
	LL i,j;
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
	}
	for(i=1;i<=maxa;i++) {
		if (cnt[i]==0) continue;
		for(j=i;j<=maxa;j+=i) {
			if (j/i!=i) z[j]+=cnt[i]*cnt[j/i];
			else z[j]+=cnt[i]*(cnt[i]-1);
		}
	}
	LL p;
	for(i=1;i<=maxa;i++)
		ans[i]+=z[i]+ans[i-1]; 	
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&p);
		printf("%lld\n",n*(n-1)-ans[p-1]);	
	}	
	return 0;
}
