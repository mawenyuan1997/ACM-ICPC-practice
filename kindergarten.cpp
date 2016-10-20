#include<cstdio>
#include<algorithm>
using namespace std;
const long long maxn=1e6;
long long a[maxn+1],b[maxn+1],n,f[maxn+1][2]={0};

int main() {
	scanf("%lld",&n);
	long long i,m=0;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if (n==1) {
		printf("0");
		return 0;
	}
	b[++m]=1;	//set the first and the last element as turning points
	for(i=2;i<n;i++) {
		if (a[i-1]<=a[i]&&a[i]>=a[i+1]||a[i-1]>=a[i]&&a[i]<=a[i+1]) {
			b[++m]=i;
		}
	}
	b[++m]=n;
	f[1][0]=f[1][0]=0;
	for(i=2;i<=m;i++) {
		if (b[i]==b[i-1]+1) {
			f[i][0]=max(f[i-1][1]+abs(a[b[i]]-a[b[i-1]]),f[i-1][0]);
			f[i][1]=max(f[i-1][0],f[i-1][1]);
		}
		else {
			f[i][0]=max(f[i-1][0]+abs(a[b[i]]-a[b[i-1]+1]),f[i-1][1]+abs(a[b[i]]-a[b[i-1]]));
			f[i][1]=max(f[i-1][0]+abs(a[b[i]-1]-a[b[i-1]+1]),f[i-1][1]+abs(a[b[i]-1]-a[b[i-1]]));	
		}
	}
	printf("%lld",max(f[m][0],f[m][1]));
}

