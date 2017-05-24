#include <iostream>
#include <algorithm>
using namespace std;
struct e{
	int x,index;
}a[101];
int cmp(e c,e b) {
	return c.x>b.x;
}
int main() {
	int n,w,b[101];
	cin>>n>>w;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x;a[i].index=i;
		b[i]=(a[i].x+1)/2;
		w-=b[i];
		if (w<0) {
			cout<<-1;
			return 0;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n && w>0;i++) {
		int full=a[i].x;
		int actual=b[a[i].index];
		if (w>full-actual) {
			w-=(full-actual);
			b[a[i].index]=full;
		}
		else {
			b[a[i].index]+=w;
			w=0;
		}
	}
	for(int i=1;i<=n;i++) {
		cout<<b[i]<<' ';
	}
	return 0;
}
