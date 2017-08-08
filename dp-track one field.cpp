#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
const LL maxn=201,max5=maxn*18*log(10)/log(5);
LL n,k,k1;
LL a[maxn],f[maxn][max5+1]={0};
LL two[maxn], five[maxn];
int main() {
  cin>>n>>k1;
  for(int i=1;i<=n;i++) {
    cin>>a[i];
    two[i]=five[i]=0;
    while(a[i]%2==0) {
      a[i]/=2;two[i]++;
    }
    
    while(a[i]%5==0) {
      a[i]/=5;five[i]++;
    }
  }
  
  for(int k=1;k<=max5;k++)
    f[0][k]=-1;
  f[0][0]=0;
  for(int i=1;i<=n;i++) {
    for(int j=i;j>=1;j--) {
      for(int k=max5;k>=0;k--) {
        if (j==i) f[j][k]=-1;
        if (k>=five[i]&&f[j-1][k-five[i]]!=-1)
          f[j][k]=max(f[j][k],f[j-1][k-five[i]]+two[i]);
          
          //if (k<6) cout<<i<<' '<<j<<' '<<k<<' '<<f[j][k]<<endl;
      }
    }
  } 
  LL ans=0;
    for(int j=0;j<=max5;j++) {
      ans=max(ans, min((LL)j,f[k1][j]));
    }
//  for(int i=1;i<=n;i++) {
//    cout<<two[i]<<endl;
//  }
  cout<<ans<<endl;
  return 0;
}
