#include <bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int n=0,a[M],t=1,p=1;
int dp[M],f[M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../csp2062/hhhhhs.in", "r", stdin);
    int tmpa;
    while (cin >> tmpa){
        a[n++] = tmpa;
    }

    dp[0]=a[0];
    for (int i = 1; i < n; i++){
        int x=lower_bound(dp,dp+t,a[i])-dp;
        dp[x]=a[i];
        t=max(t,x+1);
    }
    f[0]=a[0];
    for (int i = 1; i < n; i++){
        int x=upper_bound(f,f+p,a[i], greater<int>())-f;
        f[x]=a[i];
        p=max(p,x+1);
    }
    cout<<p<<' '<<t<<endl;
    return 0;
}