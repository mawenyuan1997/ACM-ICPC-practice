#include <iostream>
using namespace std;
const int maxn=300;
int g[maxn][maxn]={0},n,rec[31];
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
int rx(int p,int q,int dir,int i,int j) {
	if (dir==3||dir==7)
		return i+j-q;
	if (dir==1||dir==5)
		return i-j+q;
	if (dir==2||dir==6)
		return 2*i-p;
	return p;	
}
int ry(int p,int q,int dir,int i,int j) {
	if (dir==3||dir==7)
		return i+j-p;
	if (dir==1||dir==5)
		return -i+j+p;
	if (dir==4||dir==0)
		return 2*j-q;
	return q;	
}
void dfs(int level,int x,int y,int dir) {
	if (level>n) return;
	int i,j,step;
	for(i=x,j=y,step=0;step<rec[level];i+=dx[dir],j+=dy[dir],step++) {}
	dfs(level+1,i,j,(dir+7)%8);
	i+=maxn/2;j+=maxn/2;
	for(int p=0;p<300;p++)
		for(int q=0;q<300;q++) {
			if (g[p][q]==1) {
				g[rx(p,q,dir,i,j)][ry(p,q,dir,i,j)]=1;
			}
		}			
	for(i=x+maxn/2+dx[dir],j=y+maxn/2+dy[dir],step=0;step<rec[level];i+=dx[dir],j+=dy[dir],step++) {
		g[i][j]=1;
	}
	
}
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) 
		cin>>rec[i];
	dfs(1,-1,-1,2);
	int sum=0;
	for(i=0;i<300;i++)
		for(j=0;j<300;j++)
			sum+=g[i][j];
	cout<<sum;
	return 0;
} 
