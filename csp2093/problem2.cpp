#include <iostream>
using namespace std;
long long a[300000];
bool check(int b,int n,int k){
    long long d=0;
    for(int i=0;i<n;i++)
        d+=(a[i]-1+b)/b-1;
    return k>=d;
}
int main()
{
    int n,k,m=0;
    cin>>n>>k;
    for (int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i]>m)
            m=a[i];
    }
    int l=(m-1)/(k+1),r=m;
    while (l+1<r){
        int mid=(l+r)/2;
        if(check(mid,n,k))
            r=mid;
        else
            l=mid;
    }
    cout<<r<<endl;
    return 0;
}