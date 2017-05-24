#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1e5+1,N=400,MOD=1e9+7;
int n,a[maxn],b[N]={0};
bool isprime[N];
long long ex(long long x,long long y) {
	if (y==0) return 1;
	long long k=ex(x,y/2);
	if (y&1) return x*k*k%MOD;
	else return k*k%MOD;
}
void getprime() {
	int i,j;
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(i=2;i<N;i++) {
		if (isprime[i]) {
			for(j=i*i;j<N;j+=i)
				isprime[j]=false;
		}
	}
}
int main() {
	getprime();
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if (isprime[a[i]]) b[a[i]]++;
		for(int j=2;j<=a[i]/2;j++) 
			if (isprime[j] && a[i]%j==0) {
				b[j]++;
			}
	}
	long long ans=0;
	for(int i=2;i<N;i++) {
		if (isprime[i] && b[i]>0) {
			ans=(ans+ex(2,b[i])+MOD-1)%MOD;
		}
	}
	cout<<(ex(2,n)-1+MOD+MOD-ans)%MOD;
	return 0;
} 
