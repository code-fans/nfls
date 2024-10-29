#include <iostream>
using namespace std;
int main()
{
    int n,m,a;
    long long ans[100000]={0},p=1000000007;
    cin>>n>>m;
    ans[0]=1;
    ans[1]=1;
    for (int i = 0; i < m; i++){
        cin>>a;
        ans[a]=-1;
    }
    if(ans[1]==-1)
        ans[1]=0;

    for (int i = 2; i <= n; i++){
        if(ans[i]!=-1){
            ans[i]=ans[i-1]+ans[i-2];
            ans[i]%=p;
        } else {
            ans[i]=0;
        }
    }
    cout<<ans[n]<<endl;
    return 0;
}