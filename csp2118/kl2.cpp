#include <bits/stdc++.h>
using namespace  std;
struct kl2{
    long long a;
    long long b;
};
kl2 a[10000000];
bool cmp(kl2 a,kl2 b){
    return a.a*b.b<b.a*a.b;
}
int main()
{
    long long n;
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>a[i].a;
    for (int i = 0; i < n; i++)
        cin>>a[i].b;
    sort(a,a+n,cmp);
    long long ans=0,now=0;
    for (int i = 0; i < n; i++){
        now+=a[i].a;
        ans+=a[i].b*now;
    }
    cout<<ans<<endl;
    return 0;
}