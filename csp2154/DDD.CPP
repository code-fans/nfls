#include <bits/stdc++.h>
using namespace std;
int n,a[10000000][2];
long long dfs(int c,long long ans,int s){
    if(c==0)
        return ans;
    long long ans1=1000000000000;
    for (int i = 0; i < n; i++){
        if(a[i][0]!=0){
            int x=a[i][0];
            a[i][0]=0;
            if(s==1000)
                ans1=min(ans1,dfs(c-1,ans,i));
            else
                ans1=min(ans1,dfs(c-1,ans+max(a[s][1],x),i));
            a[i][0]=x;
        }
    }
    return ans1;
}
int main()
{
    long long ans;
    cin>>n;
    for (int i = 0; i < n; i++)cin>>a[i][0];
    for (int i = 0; i < n; i++)cin>>a[i][1];
    cout<<dfs(n,n,1000)<<endl;
    return 0;
}