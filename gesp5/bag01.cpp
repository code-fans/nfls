#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
const int N = 10010;
int dp[N];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++){
        int v, w;
        cin>>v>>w;
        for(int k = m; k >0; k--){
            if(k - v >= 1){
                dp[k] = min(dp[k], dp[k - v] + w);
            } else{
                dp[k] = min(dp[k],  w);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}