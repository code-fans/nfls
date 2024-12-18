#include <bits/stdc++.h>
using namespace std;
long long ans=0,n,a[1000000],mcshu[1000000];
int main()
{
    cin>>n;
    long long m=0;
    for (int i = 0; i < n; i++){
        cin>>a[i];
        mcshu[i]=(1<<i)-m;
        m+=a[i];
        m*=2;
    }
    cin>>a[n];
    mcshu[n]=a[n];
    long long shang=mcshu[n];
    ans+=a[n];
    for (int i = n-1; i >= 0; i--){
        if(shang/2+a[i]>mcshu[i]){
            cout<<-1<<endl;
            return 0;
        }
        ans+=a[i]+min(shang,mcshu[i]-a[i]);
        shang=min(shang,mcshu[i]-a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
