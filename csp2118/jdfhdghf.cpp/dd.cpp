#include <bits/stdc++.h>
using namespace std;
int a[1000000],dp[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        dp[i]=dp[i-1]+a[i];
    }
    int minn = 0, ans = -100000000000000;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i] - minn);
        minn = min(minn, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}