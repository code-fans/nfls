#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    long long a,ans=-1e20;
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        cin>>a;
        if(a>ans)
            ans=a;
    }
    for (int i = 0; i < m; i++){
        cin>>a;
        if(n==1 || a>0)
            ans+=a;
    }
    
    cout<<ans<<endl;
    
    return 0;
}