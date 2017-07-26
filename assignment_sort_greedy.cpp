#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;
const int maxn=1000+17,maxk=2000+17;
int main() {
	int n,k,a[maxn],b[maxk],p;
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=k;i++) {
		cin>>b[i];
	}
	sort(b+1,b+k+1);
	sort(a+1,a+n+1);
	LL ans=2*1e9;
	for(int start=1;start<=k-n+1;start++) {
		LL maxtime=0;
		for(int j=0;j<n;j++) {
			maxtime=max(maxtime,(LL)abs(a[j+1]-b[start+j])+abs(b[start+j]-p));
		}
		ans=min(ans,maxtime);
	}
	cout<<ans;
	return 0;
}
