#include <bits/stdc++.h>
using namespace std;
int b[1000000];
int dp[100010]={0};
int lis(int n){
    int ans=0;
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < n; i++) {
        int maxi = 0;
        for (int j = 0; j < i; j++) {
            if (b[i] > b[j]) {
                maxi = max(dp[j], maxi);
            }
        }
        dp[i] = maxi + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int bis(int n){
    int ans=0;
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < n; i++) {
        int maxi = 0;
        for (int j = 0; j < i; j++) {
            if (b[i] <= b[j]) {
                maxi = max(dp[j], maxi);
            }
        }
        dp[i] = maxi + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main()
{
    //freopen("../csp2062/hhhhhs.in", "r", stdin);
    int n=0;
    while(cin>>b[n]){
        n++;
    }
    cout<<bis(n)<<endl<<lis(n)<<endl;
    return 0;
}