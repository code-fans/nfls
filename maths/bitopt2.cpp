#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,ans=0;
    cin>>n;
    bool a=n<0;
    if(a)
        n = ~n;
    while(n){
        ans+=n%2;
        n/=2;
    }
    if(a)
        ans = 32-ans;
        
    cout<<ans<<endl;
    return 0;
}