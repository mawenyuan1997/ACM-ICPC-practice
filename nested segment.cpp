#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=2e5;
int n;
struct e {
	int l,r,order,ans; 
}a[maxn+1];
int ans[maxn+1],b[maxn+1],bit[maxn+1]={0};
int cmp(e a,e b) {
	return a.l>b.l;
}
void discrete(int sub_a[]) {
	sort(sub_a+1,sub_a+n+1);
	int size=unique(sub_a+1,sub_a+n+1)-sub_a-1;
	for(int i=1;i<=n;i++)
		a[i].r=lower_bound(sub_a+1,sub_a+size+1,a[i].r)-sub_a;
}
int lowbit(int x) {
    return x&(-x);
}
void edit(int i, int delta) {
    for (int j = i; j <= n; j += lowbit(j))
        bit[j] += delta;
}
int sum (int k) {
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        ans += bit[i];
    return ans;
}

int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].order=i;
		b[i]=a[i].r;
	}
	discrete(b);
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++) {
		edit(a[i].r,1);
		ans[a[i].order]=sum(a[i].r-1);
	}
	for(i=1;i<=n;i++)
	 	printf("%d\n",ans[i]);
	return 0;
}
