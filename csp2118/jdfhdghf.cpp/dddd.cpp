#include <bits/stdc++.h>
using namespace std;
long long a[1000000],f[2000000],h[1000000];
int main()
{
    long long n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
        long long mx=0;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]&&mx<f[j])
                mx=f[j];
        }
        f[i]=mx+1;
    }
    for(int i=n-1;i>=0;--i){
        long long mx=0;
        for (int j = n-1; j >= i; j--){
            if(a[j]<a[i]&&mx<h[j])
                mx=h[j];
        }
        h[i]=mx+1;
    }
    long long mx=0;
    for(int i=0;i<n;i++)
        if(mx<f[i]+h[i])
            mx=f[i]+h[i];
    cout<<n-mx+1<<endl;
    return 0;
}