#include <bits/stdc++.h>
using namespace std;
long long x[200000],y[200000],h[200000];
long long l=1<<30,r=0,maxh=0;
int main()
{
    freopen("../csp2172/input.txt","r", stdin);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>x[i]>>y[i];
        long long h1;
        cin>>h1;
        for(long long j=x[i];j<y[i];j++){
            h[j]=max(h1,h[j]);
        }
        maxh=max(maxh,h1);
    }
    for(int i=0;i<=1000;i++)
        if(h[i]){
            l=i;
            break;
        }
    for (int i = 1000; i >= 0; i--)
        if(h[i]){
            r=i;
            break;
        }
    long long ans=0;
    for (int i = l; i <= r+1; i++){
        ans+=abs(h[i]-h[i-1]);
        ans+=(h[i]>0);
    }
    cout<<ans<<endl;
    for (long long i = maxh; i >= 1; i--){
        long long shangnum=0;
        for (long long j = l; j <= r; j++){
            if (h[j]==i)
                cout<<"#";
            else if((h[j-1]<=i&&i<=h[j])||(h[j+1]<=i&&i<=h[j])){
                cout<<"#";
            }else
                cout<<".";
        }
        cout<<endl;
    }
    for(int i=l;i<=r;i++)
        cout<<"*";
    cout<<endl;
	return 0;
}