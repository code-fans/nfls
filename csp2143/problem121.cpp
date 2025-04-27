#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,ans=0;
    cin>>n;
    for (int i = 2; i <= sqrt(n); i++){
        int o=0;
        while (n%i==0){
            n/=i;
            o++;
        }
        for(int j=1;j <= o;j++){
            o-=j;
            ans++;
        }
    }
    if(n!=1)
        ans++;
    cout<<ans<<endl;
    return 0;
}