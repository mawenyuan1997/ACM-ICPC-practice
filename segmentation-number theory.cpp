#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;
const int maxn=1e2+17,maxsq=sqrt(1e9);
const ll inf=1e12;
ll n,k,a[maxn];
ll pd[maxn*2*maxsq];
int main() {
	//cin>>n>>k;
	scanf("%lld%lld",&n,&k);
	ll suma=0,maxa=0,j=0;
	for(int i=1;i<=n;i++) {
		//cin>>a[i];
		scanf("%lld",&a[i]);
		suma+=a[i];
		for(int p=1;p*p<=a[i];p++) {
			pd[j++]=p;pd[j++]=(a[i]+p-1)/p;
		}
	}
	pd[j++]=inf;
	sort(pd,pd+j);
	j=unique(pd,pd+j)-pd;
	
	ll ans=1;
	for(int i=0;i<j-1;i++) {
		int l=pd[i],r=pd[i+1];
		ll sigma=0;
		for(int p=1;p<=n;p++) 
			sigma+=(a[p]+l-1)/l;
		ll d=(suma+k)/sigma;
		/*if (d>=r) {
			d=r-1;
		}*/
		if (d>=l&&d>ans) {
			ans=d;
		}
	}
	//cout<<ans;
	printf("%lld",ans);
	return 0;
} 
