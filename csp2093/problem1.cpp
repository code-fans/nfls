#include <bits/stdc++.h>
using namespace std;
long long a[200000],b[200000];
int main()
{
	int n,n1,s;
	cin>>n>>n1>>s;
    long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
        sum += a[i];
        a[i] = sum;
    }
    sum = 0;
	for(int i=0;i<n1;i++){
		cin>>b[i];
        sum += b[i];
        b[i] = sum;
    }
    long long sy;
    int ans = upper_bound(b, b+n1, s) - b;
	for(int i=0; i<n && a[i]<=s; i++){
        int bpos = upper_bound(b, b+n1, s - a[i]) - b;
        if(ans < i + bpos + 1){
            ans = i + bpos + 1;
        }
	}
	cout<<ans<<endl;
	return 0;
}