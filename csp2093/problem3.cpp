#include <iostream>
using namespace std;
long long c[200000];
bool cheak(long long b,long long n,long long k,long long z,long long f){
    long long d=0;
    for (long long i = 0; i < n; i++)
        if((c[i]-f*b)>0)
            d+=(c[i]-f*b+z-f-1)/(z-f);
    return d<=k;
}

int main(){
    long long n,a,b,m=0;
    cin>>n>>a>>b;
    for (long long i = 0; i < n; i++){
        cin>>c[i];
        if(m<c[i])
            m=c[i];
    }
    long long l=(m+a-1)/a-1, r=(m+b-1)/b+1;

    while (l+1<r){
        long long mid=(l+r)/2;
        if(cheak(mid,n,mid,a,b))
            r=mid;
        else
            l=mid;
    }

    cout<<r<<endl;
    return 0;
}