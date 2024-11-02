#include <iostream>
#include <algorithm>
using namespace std;
long long a[200200]={0},b[200200]={0};
int main()
{
	long long n,n1,s;
	cin>>n>>n1>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n1;i++){
		cin>>b[i];
		b[i]+=b[i-1];
	}
	int ans = upper_bound(a+1,a+n+1,s)-a-1;
	for (int i = 1; i <= n1 && b[i]<=s; i++){
		int ab = upper_bound(a+1,a+n+1,s-b[i])-a-1;
		if(ab+i>ans)
			ans=ab+i;
	}
	
	cout<< ans << endl;
	return 0;
}
/**
 4 4 5
 2 2 2 2
 1 3 3 3 
 */