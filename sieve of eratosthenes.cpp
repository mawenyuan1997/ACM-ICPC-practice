#include <iostream>
#include <cmath>
#define LL long long
using namespace std;
const int MOD=1e9+7,maxn=5000000+1;
bool isprime[maxn];
int f[maxn];
int main() {

	int t,l,r;
	cin>>t>>l>>r;
	for(int i=2;i<=r;i++) {
		isprime[i]=true;f[i]=MOD;
	}
	f[2]=1;
	f[3]=3;
	f[4]=3;
	for(int i=2;i<=r;i++) {
		if (isprime[i]) {	
			f[i]=(LL)i*(i-1)/2%MOD;
			for(int j=i;(LL)i*j<=r;j++) {
				int n=j*i;
				if (n<0) cout<<i<<" "<<j<<" "<<n<<endl;
				isprime[n]=false;
			}
		}
	}
	for(int i=sqrt(r);i>=2;i--) {
		if (isprime[i]) {
			for(int j=i;(LL)i*j<=r;j++) {
				int n=j*i;
				f[n]=((LL)n*(i-1)/2%MOD+f[j])%MOD;
			}
		}
	}
	int sum=0,tm=1;
	for(int i=l;i<=r;i++) {
		sum=(sum+(LL)f[i]*tm%MOD)%MOD;
		tm=(LL)tm*t%MOD;
	}
	cout<<sum<<endl;
	return 0;
} 
