#include<cstdio>
using namespace std;
int n,m;
const int maxn=400001,maxm=400001;
struct e {
	int x,y,next;
}edge[2*maxm];
int pre[maxn]={0},visit[maxn]={0},cnt=0,ans[maxm+1][2];
void add(int x,int y) {
	edge[++cnt].x=x;
	edge[cnt].y=y;
	edge[cnt].next=pre[x];
	pre[x]=cnt;
}
void dfs(int last,int index,int k) {
	visit[k]=1;
	ans[(index+1)/2][0]=last;
	ans[(index+1)/2][1]=k;
	for(int i=pre[k];i;i=edge[i].next) {
		int y=edge[i].y;
		if (visit[y]==1&&y!=last) {
			ans[(i+1)/2][0]=k;
			ans[(i+1)/2][1]=y;
		}
		if (visit[y]==0)
			dfs(k,i,y);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		ans[i][0]=x;ans[i][1]=y;
	}
	dfs(0,0,1);
	for(i=1;i<=m;i++) {
		printf("%d %d")
	}
} 
