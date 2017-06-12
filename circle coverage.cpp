#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
int n;
double pi=acos(-1.0);
struct circle{
	int r,x,y,cover;
}cir[1001];
int cmp(circle a,circle b) {
	return a.r>b.r;
}
long long dist_sq(circle a,circle b) {
	return (long long) (a.x-b.x)*(a.x-b.x)+(long long) (a.y-b.y)*(a.y-b.y);
}
int main() {
	//cin>>n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		//cin>>cir[i].x>>cir[i].y>>cir[i].r;
		scanf("%d%d%d",&cir[i].x,&cir[i].y,&cir[i].r);
	}
	sort(cir+1, cir+1+n, cmp);
	cir[1].cover=0;
	for(int i=2;i<=n;i++) {
	//	printf("%lld\n",dist_sq(cir[i],cir[i-1]));
		for(int j=i-1;j>=1;j--) {	
			if (dist_sq(cir[i],cir[j])<(long long)cir[j].r*cir[j].r) {
				cir[i].cover=cir[j].cover+1;break;
			}
		}
	}
	long long answer=0;
	for(int i=1;i<=n;i++) {
		if (cir[i].cover==0)
			answer+=(long long) cir[i].r*cir[i].r;
		cir[i].cover--;
	}
	for(int i=1;i<=n;i++) {
		if (cir[i].cover>=0) {
			if (cir[i].cover&1)
				answer-=(long long) cir[i].r*cir[i].r;
			else
				answer+=(long long) cir[i].r*cir[i].r;
		}
	}
    printf("%.8lf",(double) answer*pi);
	return 0;
}
