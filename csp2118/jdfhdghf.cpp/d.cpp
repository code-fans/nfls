#include <bits/stdc++.h>
using namespace std;
int a[2000000];
long long dp[2000000],dp2[2000000];
int main() {
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++){
        dp[i]=max(dp[i - 1],dp[i - 3]+a[i - 1]+a[i]);
    }
    return 0;
}