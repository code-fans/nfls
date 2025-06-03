#include <bits/stdc++.h>
using namespace std;
long long inf=1e9+7;
int m[1000000];
int main()
{
    long long n,n1,ans=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>m[i];
    sort(m+1,m+1+n);
    for(int i=0;i<n;i++){
        ans*=m[i+1]-i;
        ans%=inf;
    }
    cout<<ans<<endl;
    return 0;
}