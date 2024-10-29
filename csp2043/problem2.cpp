#include <iostream>
using namespace std;
int dp[55][20000]={{0}};
int main()
{
    int n,m,a[1000],b[1000];
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        cin>>a[i]>>b[i];
    }
    dp[0][0]=1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if(dp[i-1][j]==1){
                dp[i][j]=1;
                for (int k = 0; k < b[i-1] &&  (k+1)*a[i-1]+j <= m; k++){
                    dp[i][( (k+1)*a[i-1]+j) ]=1;
                }
            }
        }
    }
    if(dp[n][m])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}