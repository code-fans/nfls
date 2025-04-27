#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
int dp[4000][4000]={{0}};
char s[4000],s1[4000],ans[4000];
int main(){
    int n,m;
    const char * sp = s+1;
    const char * sp1 = s1+1;
    cin>>sp>>sp1;
    s[0]=32;
    s1[0]=32;
    n=strlen(s)-1;
    m=strlen(s1)-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==s1[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int ans1=dp[n][m];
    int i=n,j=m;
	while(dp[i][j] > 0){
		if(s[i] == s1[j]){
            ans[dp[i][j]] = s[i];
            i--;
            j--;
        }
		else if(dp[i][j] == dp[i - 1][j]) 
            i--;
		else
            j--;
	}
    for(int i=1;i<=ans1;i++)
        cout<<ans[i];
    cout<<endl;
	return 0;
}