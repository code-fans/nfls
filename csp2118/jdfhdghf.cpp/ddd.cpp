#include <bits/stdc++.h>
using namespace std;
int a[1000000],dp[1000000][2];
int main()
{
    int n;
    cin>>n;
    for (int i = 2; i <= n+1; i++)
        cin>>a[i];
    for (int i = 2; i <= n+1; i++){
        dp[i][0]=max(dp[i-2][0],dp[i-2][1])+a[i];
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[n+1][0],dp[n+1][1])<<endl;
    return 0;
}