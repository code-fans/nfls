#include <bits/stdc++.h>
using namespace std;
int n,v,w[10000000],jia[10000000],dp[1000000],m;
int main()
{
    cin>>v>>n;
    for (int i = 0; i < n; i++){
        cin>>m;
        for (int j = 1; j <= m; j++)
            cin>>w[j]>>jia[j];
        for (int j = v; j >= 0; j--)
            for (int k = 1; k <= m; k++)
                if(j-w[k]>=0)
                    dp[j]=max(dp[j],dp[j-w[k]]+jia[k]);
    }
    cout<<dp[v]<<endl;
    return 0;
}