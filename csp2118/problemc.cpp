#include <bits/stdc++.h>
using namespace std;
long long n,a[300300]={0},b,c[300300][2]={{0}},h1=1,and1=0,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        cin>>b;
        a[i]= a[i-1]+b;
    }
    for (int i = 1; i <= m; i++){
        a[i+n]= a[n]+a[i];
    }
    int ans=a[1],ans1=1,ans2=1;
    for (int i = 1; i <= n+m-1; i++){
        if(ans<a[i]-c[and1][0]){
            ans=a[i]-c[and1][0];
            ans1=c[and1][1]%n+1;
            ans2=(i-1)%n+1;
        }
        if(c[and1][1]==i-m)
            and1++;
        while(h1>and1 && c[h1-1][0]>=a[i])
            h1--;
        c[h1][1]=i;
        c[h1][0]=a[i];
        h1++;
    }
    cout<<ans<<' '<<ans1<<' ' <<ans2<<endl;
    return 0;
}