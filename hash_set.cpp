#include <iostream>
#include <cstdlib>
#include <map>
 
using namespace std;

int main()
{
    map<long long,long long> hs,ht;
    long long n,a[100001];
    cin>>n;
	long long i,sum=0;
	for(i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	if (sum&1) {
		cout<<"NO";
		return 0;
	}
	//int b[maxn]={0};
	for(i=1;i<=n;i++) {
		if (a[i]>sum/2) {
			cout<<"NO";
			return 0;
		}
		if (hs.find(a[i])==hs.end()) hs[a[i]]=1;
		else hs[a[i]]++;
	}	
	long long j=0;
	for(i=1;i<=n;i++) {
		//cout<<j<<' '; 
		if (j==sum/2 || hs[sum/2-j]>0 || ht[j-sum/2]>0) {
			cout<<"YES";
			return 0;
		}
		hs[a[i]]--;
		j+=a[i];
		ht[a[i]]++;
		//ht.print_inorder();cout<<endl;
	}
	cout<<"NO";
	return 0;
} 
