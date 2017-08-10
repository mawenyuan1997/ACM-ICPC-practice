#include <iostream>
#include <vector>
typedef long long LL;
using namespace std;
const LL maxx=1e12;
vector<LL> pf;
bool isprime[1000010];
LL gcd(LL x, LL y) {
  if (x%y==0) return y;
  else return gcd(y,x%y); 
}
int main() {
  LL x, y;
  cin>>x>>y;
  LL p=2,x1=x;
  LL ans=0;
  for(int i=1;i<1e6;i++) {
    isprime[i]=true;
  }

  for(int i=2;i<=1e6;i++) {
    if (isprime[i]) { 
      for(int j=i;(LL)i*j<=1e6;j++) {
        int n=j*i;
        isprime[n]=false;
      }
    }
  }
  while(x1!=1) {
    while((x1%p!=0 || !isprime[p]) && p<=1e6) p++;
    if (p>1e6) {
      p=x1;
    }
    while(x1%p==0) {
      x1/=p;
      pf.push_back(p);
    }
  }
  while(y!=0) {
    LL g=gcd(x,y);
    LL mi=maxx,k,i1;
    for(int i=0;i<pf.size();i++) {
      LL ty=(y/(pf[i]*g)*(pf[i]*g));
      if ((y-ty)/g<mi) {
        mi=(y-ty)/g;
        k=ty;
        i1=i;
      }
    }
    if (pf.size()!=0) {
      y=k;
      ans+=mi;
      pf.erase(pf.begin()+i1);
    }
    else {
      ans+=y/x;
      y=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}
