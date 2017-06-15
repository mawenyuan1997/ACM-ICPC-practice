#include <iostream>
#include <queue>
#include <map>
using namespace std;
int n,m,di,dj;
char c[101][101];
struct Position{
	int x,y;
};
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			cin>>c[i][j];
			if (c[i][j]=='F') {
				di=i;dj=j;
			} 
	}
	queue<pair<int,int> > q;
	map<pair<int,int>,int> back;
	q.push(make_pair(1,1));
	back[make_pair(1,1)]=-1;
	int sx[4]={0,0,1,-1},sy[4]={1,-1,0,0};
	while(!q.empty()) {
		pair<int,int> p=q.front();
		if (c[p.first][p.second]=='F') break;
		
		for(int i=0;i<4;i++) {
			int x1=p.first+sx[i],y1=p.second+sy[i];
			if (x1>=1&&x1<=n&&y1>=1&&y1<=m&&c[x1][y1]!='*' && back.find(make_pair(x1,y1))==back.end()) {
				back[make_pair(x1,y1)]=i;
				q.push(make_pair(x1,y1));
			}
		}
		q.pop();
	}
	int k=0,x=di,y=dj,path[500001];
	while(back[make_pair(x,y)]!=-1) {
		int i=back[make_pair(x,y)];
		path[++k]=i;
		x-=sx[i];y-=sy[i];
	}
	x=1;y=1;
	int swapud=0,swaplr=0;
	while(true) {
		switch(path[k]) {
			case 0:if (swaplr==0) cout<<'R'<<endl; else cout<<'L'<<endl;break;
			case 1:if (swaplr==0) cout<<'L'<<endl; else cout<<'R'<<endl;break;
			case 2:if (swapud==0) cout<<'D'<<endl; else cout<<'U'<<endl;break;
			case 3:if (swapud==0) cout<<'U'<<endl; else cout<<'D'<<endl;
		}
		int x1,y1;
		cin>>x1>>y1;
		if (x1==di&&y1==dj) break;
		if (x+sx[path[k]]!=x1 || y+sy[path[k]]!=y1) {
			if (path[k]<2) swaplr=1;
			else swapud=1;
		}
		else {
			k--;x=x1;y=y1;
		}
	}
	return 0;
}
