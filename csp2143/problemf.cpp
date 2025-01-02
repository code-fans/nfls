#include <bits/stdc++.h>
using namespace std;
int a[1000000][61];
int main()
{
    int n,k;
    cin>>n>>k;
    long long maxn=0;
    for (int i = 0; i < k; i++){
        long long n1,c;
        cin>>n1;
        for(int j=0;j<n1;j++){
            cin>>c;
            a[c][i]++;
            maxn=max(maxn,c);
        }
    }
    long long l=1,r;
    long long all=0,zhong[61]={0};
    for (int i = 0; i < n; i++){
        for(int j=0;j<k;j++){
            if(a[i][j])
                all|=1ll<<j;
            zhong[j]+=a[i][j];
        }
        if(all==(1ll<<k)-1){
            r=i;
            break;
        }
    }
    long long ans=r-l;
    bool can=false;
    while (1){
        if(can==false){
            ans= min(ans , r - l ) ;
            l++;
            for(int i=0;i<k;i++){
                zhong[i]-=a[l-1][i];
                if(zhong[i]==0)
                    can=true;
            }
            if(can&&r==maxn)
                break;
        }else{
            r++;
            can=false;
            for(int i=1;i<k;i++){
                zhong[i]+=a[r][i];
                if(zhong[i]<1)
                    can=true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}