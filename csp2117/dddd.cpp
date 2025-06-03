#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,num,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lld",&num);
        ans^=num;
    }
    cout<<ans<<endl;
    return 0;
}