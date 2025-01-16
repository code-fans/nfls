#include <bits/stdc++.h>
using namespace std;
long long dp[100000000]={0};
long long bfs(long long n,long long a,long long b,long long c){
    if(n<=c)
        return 1;
    if(dp[n]) return dp[n];
    long long ans = bfs(n-a,a,b,c) + bfs(n-b,a,b,c);
    dp[n]=ans%1000000007;
    return dp[n];
}

int main()
{
    long long n,a,b,c;
    cin>>n>>a>>b>>c;
    cout<<bfs(n,a,b,c)<<endl;
    return 0;
}