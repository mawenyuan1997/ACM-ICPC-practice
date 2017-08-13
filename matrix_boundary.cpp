#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const LL maxn=2e5;
LL n,value;
LL a[maxn+1];
LL T[10][10];
LL solve1() {
  for(int i=0;;i++) {
    for(int j=1;j<=n;j++)
      if (a[j]>=value) return i;
    for(int j=2;j<=n;j++) {
      a[j]+=a[j-1];
    }
  }
}
void multi(LL (&result)[10][10],LL (&aa)[10][10],LL (&bb)[10][10]) {
  LL cc[10][10];
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      LL s=0;
      for(int k=1;k<=n;k++)
         if (log(aa[i][k])/log(10)+log(bb[k][j])/log(10)<18 && s>=0) s+=aa[i][k]*bb[k][j];
         else s=1e18;
      cc[i][j]=s;
    }
  }
  
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      result[i][j]=cc[i][j];
    }
  }
}
bool check(LL x) {
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if (i>=j) T[i][j]=1;
      else T[i][j]=0;
  LL res[10][10];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if (i==j) res[i][j]=1;
      else res[i][j]=0;
  while(x!=0) {
    if (x&1) multi(res,res,T);
    x/=2;
    multi(T,T,T);
  }
  
  for(int i=1;i<=n;i++) {
    LL s=0;
    for(int j=1;j<=n;j++) {
      if (log(res[i][j])/log(10)+log(a[j])/log(10)<18 && s>=0) s+=res[i][j]*a[j];
      else return true;
      if (s>=value) return true;
    }
    if (s>=value||s<0) return true;
    
  }

  return false;
}
LL solve2() {
  LL front=0,tail=1e18,ans;
  while(front<=tail) {
    LL mid=(front+tail)/2;
    if (check(mid)) {
      ans=mid;
      tail=mid-1;
    }
    else {
      front=mid+1;
    }
  }
  return ans;
}
int main() {
  cin>>n>>value;
  LL x=0,p=0;
  while(x==0) {
    cin>>x;p++;
  }
  a[1]=x;n=n+1-p;
  for(int i=2;i<=n;i++){
    cin>>a[i];
  }
  if (n>=10)
    cout<<solve1()<<endl;
  else
    cout<<solve2()<<endl;
  return 0;
}

