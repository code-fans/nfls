#include <bits/stdc++.h>
using namespace std;
long long dp[100000]={0},b[10000],n;
int main()
{
    cin>>n;
    long long ans=0;
    for (int i = 0; i < n; i++){
        long long maxi=0;
        cin>>b[i];
        for (int j = 0; j < i; j++){
            if(b[i]>b[j]){
                maxi= max(dp[j], maxi); 
            }
        }
        dp[i]=maxi+1;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}