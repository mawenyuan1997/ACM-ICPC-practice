#include<cstdio>
using namespace std;
const int maxn=200000+1;
struct e {
	int x,y,next;
}edge[maxn];
int n,ans=0;
int pre[maxn]={0},cnt=0,father[maxn];
int b[maxn],rootnum=0;
int visit[maxn]={0};
void add(int s,int t) {
	edge[++cnt].x=s;
	edge[cnt].y=t;
	edge[cnt].next=pre[s];
	pre[s]=cnt;
}
void dfs(int ori,int k) {
	int i;
	visit[k]=1;
	for(i=pre[k];i;i=edge[i].next) {
		int j=edge[i].y;
		if (visit[j]==0) {
			dfs(ori,j);
		}
		else if (j==ori) {
			father[j]=j;
			rootnum++;
			b[rootnum]=j;
			if (rootnum==1) ans++; 
		}
	}
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&father[i]);
		if (father[i]==i) {
			rootnum++;
			b[rootnum]=i;
		} else 
			add(father[i],i);
	}
	for(i=1;i<=rootnum;i++) 
		dfs(b[i],b[i]);
	for(i=1;i<=n;i++) {
		if (visit[i]==0) {
			dfs(i,i);
		}
	}
	for(i=2;i<=rootnum;i++) {
		father[b[i]]=b[1];ans++;
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		printf("%d ",father[i]);
	return 0;
}
