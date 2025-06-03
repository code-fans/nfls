#include <bits/stdc++.h>
using namespace std;
int n,h,d;
int a[5000][5000],dp[5000][5000],dp1[10000];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>h>>d;
    for (int i = 1; i <= n; i++){
        int c;
        cin>>c;
        for (int j = 1; j <= c; j++){
            int num=0;
            cin>>num;
            a[i][num]++;
        }
        for(int j=1;j<=h;j++)
            dp[i][j]=-1000;
        dp[i][0]=0;
    }
    for (int i = 1; i <= h; i++){
        dp1[i]=-1000;
        for (int j = 1; j <= n; j++){
            dp[j][i]=a[j][i]+dp[j][i-1];
            if(i>=d)
                dp[j][i]=max(dp[j][i],a[j][i]+dp1[i-d]);
            dp1[i]=max(dp1[i],dp[j][i]);
        }
    }
    cout<<dp1[h]<<endl;
    return 0;
}